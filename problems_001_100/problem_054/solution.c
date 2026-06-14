#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int card_value(char c) {
    if (c >= '2' && c <= '9') return c - '0';
    if (c == 'T') return 10;
    if (c == 'J') return 11;
    if (c == 'Q') return 12;
    if (c == 'K') return 13;
    if (c == 'A') return 14;
    return 0;
}

int cmp_desc(const void *a, const void *b) {
    return *(int*)b - *(int*)a;
}

int evaluate(int vals[5], int suits[5], int rank[6]) {
    int sorted[5];
    memcpy(sorted, vals, 5 * sizeof(int));
    qsort(sorted, 5, sizeof(int), cmp_desc);

    int counts[15] = {0};
    for (int i = 0; i < 5; i++) counts[sorted[i]]++;

    int pairs = 0, three = 0, four = 0;
    int pair_vals[2] = {0}, three_val = 0, four_val = 0;
    int kickers[5];
    int ki = 0;

    for (int v = 14; v >= 2; v--) {
        if (counts[v] == 4) { four = 1; four_val = v; }
        else if (counts[v] == 3) { three = 1; three_val = v; }
        else if (counts[v] == 2) { pair_vals[pairs++] = v; }
        else if (counts[v] == 1) { kickers[ki++] = v; }
    }

    int flush = 1;
    for (int i = 1; i < 5; i++) {
        if (suits[i] != suits[0]) { flush = 0; break; }
    }

    int straight = 0;
    int high_straight = 0;
    if (sorted[0] - sorted[4] == 4) {
        int unique = 1;
        for (int i = 1; i < 5; i++) if (sorted[i] == sorted[i-1]) unique = 0;
        if (unique) { straight = 1; high_straight = sorted[0]; }
    }
    if (sorted[0] == 14 && sorted[1] == 5 && sorted[2] == 4 && sorted[3] == 3 && sorted[4] == 2) {
        straight = 1;
        high_straight = 5;
    }

    if (straight && flush) {
        rank[0] = 8; rank[1] = high_straight;
        return 0;
    }
    if (four) {
        rank[0] = 7; rank[1] = four_val; rank[2] = kickers[0];
        return 0;
    }
    if (three && pairs == 1) {
        rank[0] = 6; rank[1] = three_val; rank[2] = pair_vals[0];
        return 0;
    }
    if (flush) {
        rank[0] = 5;
        for (int i = 0; i < 5; i++) rank[i+1] = sorted[i];
        return 0;
    }
    if (straight) {
        rank[0] = 4; rank[1] = high_straight;
        return 0;
    }
    if (three) {
        rank[0] = 3; rank[1] = three_val; rank[2] = kickers[0]; rank[3] = kickers[1];
        return 0;
    }
    if (pairs == 2) {
        rank[0] = 2;
        rank[1] = pair_vals[0] > pair_vals[1] ? pair_vals[0] : pair_vals[1];
        rank[2] = pair_vals[0] < pair_vals[1] ? pair_vals[0] : pair_vals[1];
        rank[3] = kickers[0];
        return 0;
    }
    if (pairs == 1) {
        rank[0] = 1; rank[1] = pair_vals[0];
        rank[2] = kickers[0]; rank[3] = kickers[1]; rank[4] = kickers[2];
        return 0;
    }
    rank[0] = 0;
    for (int i = 0; i < 5; i++) rank[i+1] = sorted[i];
    return 0;
}

int player1_wins(int r1[6], int r2[6]) {
    for (int i = 0; i < 6; i++) {
        if (r1[i] > r2[i]) return 1;
        if (r1[i] < r2[i]) return 0;
    }
    return 0;
}

int main() {
    FILE *f = fopen("p054_poker.txt", "r");
    if (!f) {
        f = fopen("../../../p054_poker.txt", "r");
        if (!f) {
            printf("Cannot open p054_poker.txt\n");
            return 1;
        }
    }

    int wins = 0;
    char line[256];
    while (fgets(line, sizeof(line), f)) {
        char cards[10][4];
        sscanf(line, "%s %s %s %s %s %s %s %s %s %s",
               cards[0], cards[1], cards[2], cards[3], cards[4],
               cards[5], cards[6], cards[7], cards[8], cards[9]);

        int v1[5], s1[5], v2[5], s2[5];
        for (int i = 0; i < 5; i++) {
            v1[i] = card_value(cards[i][0]);
            s1[i] = cards[i][1];
            v2[i] = card_value(cards[i+5][0]);
            s2[i] = cards[i+5][1];
        }

        int r1[6] = {0}, r2[6] = {0};
        evaluate(v1, s1, r1);
        evaluate(v2, s2, r2);

        if (player1_wins(r1, r2)) wins++;
    }

    fclose(f);
    printf("%d\n", wins);
    return 0;
}
