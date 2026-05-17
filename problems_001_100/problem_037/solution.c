/*
 * Project Euler - Problem 037
 * Truncatable Primes
 * https://projecteuler.net/problem=37
 *
 * Author: 0x4r35
 * Language: C
 *
 * Find the sum of the only eleven primes that are both truncatable
 * from left to right and right to left.
 * NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define LIMIT 1000000

bool sieve[LIMIT];

void build_sieve() {
    for (int i = 2; i < LIMIT; i++)
        sieve[i] = true;

    for (int i = 2; i <= (int)sqrt(LIMIT); i++) {
        if (sieve[i]) {
            for (int j = i * i; j < LIMIT; j += i)
                sieve[j] = false;
        }
    }
}

/* Check if prime when truncated from right (removing last digit) */
bool is_right_truncatable(int n) {
    while (n > 0) {
        if (!sieve[n]) return false;
        n /= 10;
    }
    return true;
}

/* Check if prime when truncated from left (removing first digit) */
bool is_left_truncatable(int n) {
    int power = 1;
    while (power <= n)
        power *= 10;
    power /= 10;

    while (n > 0) {
        if (!sieve[n]) return false;
        n %= power;
        power /= 10;
    }
    return true;
}

int main() {
    build_sieve();

    long sum = 0;
    int count = 0;

    /* Single digit primes (2, 3, 5, 7) are excluded */
    for (int i = 10; i < LIMIT && count < 11; i++) {
        if (sieve[i] && is_right_truncatable(i) && is_left_truncatable(i)) {
            sum += i;
            count++;
        }
    }

    printf("%ld\n", sum);
    return 0;
}
