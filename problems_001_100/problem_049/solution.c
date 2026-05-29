#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_permutation(int a, int b) {
    int counts[10] = {0};
    while (a > 0) {
        counts[a % 10]++;
        a /= 10;
    }
    while (b > 0) {
        counts[b % 10]--;
        b /= 10;
    }
    for (int i = 0; i < 10; i++) {
        if (counts[i] != 0) return false;
    }
    return true;
}

int main() {
    int limit = 10000;
    bool *is_prime = (bool *)malloc(limit * sizeof(bool));
    for (int i = 0; i < limit; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;

    for (int p = 2; p * p < limit; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i < limit; i += p) {
                is_prime[i] = false;
            }
        }
    }

    for (int i = 1000; i < 10000; i++) {
        if (!is_prime[i]) continue;
        if (i == 1487) continue;

        for (int step = 1; i + 2 * step < 10000; step++) {
            int j = i + step;
            int k = j + step;

            if (is_prime[j] && is_prime[k]) {
                if (is_permutation(i, j) && is_permutation(i, k)) {
                    printf("%d%d%d\n", i, j, k);
                    free(is_prime);
                    return 0;
                }
            }
        }
    }

    free(is_prime);
    return 0;
}