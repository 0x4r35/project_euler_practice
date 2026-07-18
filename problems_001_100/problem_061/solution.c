#include <stdio.h>

#define TYPES 6
#define MAX_NUMBERS 100

typedef struct {
    int value;
    int prefix;
    int suffix;
} Figurate;

Figurate numbers[TYPES][MAX_NUMBERS];
int counts[TYPES];
int used[TYPES];
int chain[6];

int figurate(int sides, int n) {
    switch (sides) {
        case 3:
            return n * (n + 1) / 2;
        case 4:
            return n * n;
        case 5:
            return n * (3 * n - 1) / 2;
        case 6:
            return n * (2 * n - 1);
        case 7:
            return n * (5 * n - 3) / 2;
        case 8:
            return n * (3 * n - 2);
        default:
            return 0;
    }
}

void build_numbers(void) {
    for (int type = 0; type < TYPES; type++) {
        int sides = type + 3;

        for (int n = 1;; n++) {
            int value = figurate(sides, n);
            if (value >= 10000) {
                break;
            }
            if (value >= 1000 && value % 100 >= 10) {
                Figurate item = {value, value / 100, value % 100};
                numbers[type][counts[type]++] = item;
            }
        }
    }
}

int already_in_chain(int depth, int value) {
    for (int i = 0; i < depth; i++) {
        if (chain[i] == value) {
            return 1;
        }
    }
    return 0;
}

int chain_sum(void) {
    int total = 0;
    for (int i = 0; i < 6; i++) {
        total += chain[i];
    }
    return total;
}

int search(int depth) {
    if (depth == 6) {
        return chain[5] % 100 == chain[0] / 100;
    }

    int next_prefix = chain[depth - 1] % 100;

    for (int type = 0; type < TYPES; type++) {
        if (used[type]) {
            continue;
        }

        used[type] = 1;
        for (int i = 0; i < counts[type]; i++) {
            Figurate item = numbers[type][i];
            if (item.prefix != next_prefix || already_in_chain(depth, item.value)) {
                continue;
            }

            chain[depth] = item.value;
            if (search(depth + 1)) {
                return 1;
            }
        }
        used[type] = 0;
    }

    return 0;
}

int main(void) {
    build_numbers();

    used[5] = 1;
    for (int i = 0; i < counts[5]; i++) {
        chain[0] = numbers[5][i].value;
        if (search(1)) {
            printf("%d\n", chain_sum());
            return 0;
        }
    }

    return 1;
}
