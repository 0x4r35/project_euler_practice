#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIMIT 1000000

int main() {
    bool *is_prime = (bool *)malloc(LIMIT * sizeof(bool));
    for (int i = 0; i < LIMIT; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;

    int prime_count = 0;
    for (int p = 2; p * p < LIMIT; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i < LIMIT; i += p) {
                is_prime[i] = false;
            }
        }
    }

    for (int i = 0; i < LIMIT; i++) {
        if (is_prime[i]) prime_count++;
    }

    int *primes = (int *)malloc(prime_count * sizeof(int));
    int idx = 0;
    for (int i = 0; i < LIMIT; i++) {
        if (is_prime[i]) primes[idx++] = i;
    }

    long long *prime_sums = (long long *)malloc((prime_count + 1) * sizeof(long long));
    prime_sums[0] = 0;
    for (int i = 0; i < prime_count; i++) {
        prime_sums[i + 1] = prime_sums[i] + primes[i];
    }

    int max_length = 0;
    long long max_prime = 0;

    for (int i = 0; i < prime_count; i++) {
        for (int j = i + max_length + 1; j <= prime_count; j++) {
            long long sum = prime_sums[j] - prime_sums[i];
            if (sum >= LIMIT) break;
            if (is_prime[sum]) {
                int length = j - i;
                if (length > max_length) {
                    max_length = length;
                    max_prime = sum;
                }
            }
        }
    }

    printf("%lld\n", max_prime);

    free(is_prime);
    free(primes);
    free(prime_sums);
    return 0;
}