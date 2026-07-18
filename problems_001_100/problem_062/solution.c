#include <limits.h>
#include <stdio.h>
#include <string.h>

#define TARGET 5
#define MAX_GROUPS 25000
#define SIG_SIZE 32

typedef struct {
    char signature[SIG_SIZE];
    int count;
    long long smallest;
} Group;

Group groups[MAX_GROUPS];
int group_count = 0;

int digit_length(long long n) {
    int length = 0;
    do {
        length++;
        n /= 10;
    } while (n > 0);
    return length;
}

void make_signature(long long n, char signature[SIG_SIZE]) {
    int digits[10] = {0};
    int pos = 0;

    do {
        digits[n % 10]++;
        n /= 10;
    } while (n > 0);

    for (int digit = 0; digit <= 9; digit++) {
        while (digits[digit]-- > 0) {
            signature[pos++] = (char)('0' + digit);
        }
    }
    signature[pos] = '\0';
}

int find_group(const char signature[SIG_SIZE]) {
    for (int i = 0; i < group_count; i++) {
        if (strcmp(groups[i].signature, signature) == 0) {
            return i;
        }
    }
    return -1;
}

long long best_exact_group(void) {
    long long best = LLONG_MAX;

    for (int i = 0; i < group_count; i++) {
        if (groups[i].count == TARGET && groups[i].smallest < best) {
            best = groups[i].smallest;
        }
    }

    return best;
}

void clear_groups(void) {
    group_count = 0;
}

void add_cube(long long cube) {
    char signature[SIG_SIZE];
    make_signature(cube, signature);

    int index = find_group(signature);
    if (index == -1) {
        index = group_count++;
        strcpy(groups[index].signature, signature);
        groups[index].count = 0;
        groups[index].smallest = cube;
    }

    groups[index].count++;
    if (cube < groups[index].smallest) {
        groups[index].smallest = cube;
    }
}

int main(void) {
    int current_length = 1;

    for (long long n = 1;; n++) {
        long long cube = n * n * n;
        int length = digit_length(cube);

        if (length != current_length) {
            long long best = best_exact_group();
            if (best != LLONG_MAX) {
                printf("%lld\n", best);
                return 0;
            }

            clear_groups();
            current_length = length;
        }

        add_cube(cube);
    }
}
