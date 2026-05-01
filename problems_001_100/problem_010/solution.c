/*
 * Project Euler - Problem 010
 * Summation of primes
 * https://projecteuler.net/problem=10
 *
 * Author: 0x4r35
 * Language: C
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIMIT 2000000

int main() {
    bool* sieve = (bool*)calloc(LIMIT, sizeof(bool));
    long long sum = 0;
    for (int p = 2; p < LIMIT; p++) {
        if (!sieve[p]) {
            sum += p;
            for (long long i = (long long)p * p; i < LIMIT; i += p) {
                sieve[i] = true;
            }
        }
    }
    printf("%lld\n", sum);
    free(sieve);
    return 0;
}
