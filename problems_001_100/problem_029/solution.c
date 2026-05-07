#include <stdio.h>
#include <stdlib.h>

int factors[10000][26];
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

int cmp(const void *a, const void *b) {
    int *pa = (int *)a;
    int *pb = (int *)b;
    for (int i = 0; i < 25; ++i) {
        if (pa[i] != pb[i]) {
            return pa[i] - pb[i];
        }
    }
    return 0;
}

int main() {
    int count = 0;
    for (int a = 2; a <= 100; ++a) {
        for (int b = 2; b <= 100; ++b) {
            int temp = a;
            for (int i = 0; i < 25; ++i) {
                factors[count][i] = 0;
                while (temp % primes[i] == 0) {
                    factors[count][i] += b;
                    temp /= primes[i];
                }
            }
            count++;
        }
    }
    qsort(factors, count, sizeof(factors[0]), cmp);
    int distinct = 1;
    for (int i = 1; i < count; ++i) {
        int diff = 0;
        for (int j = 0; j < 25; ++j) {
            if (factors[i][j] != factors[i - 1][j]) {
                diff = 1;
                break;
            }
        }
        if (diff) {
            distinct++;
        }
    }
    printf("%d\n", distinct);
    return 0;
}
