/*
 * Project Euler - Problem 003
 * Largest Prime Factor
 * https://projecteuler.net/problem=3
 *
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143?
 *
 * Author: 0x4r35
 * Language: C
 */

#include <stdio.h>
#include <inttypes.h>

int main() {
    long long n = 600851475143LL;
    long long largest = 0;

    // Divide out all factors of 2
    while (n % 2 == 0) {
        largest = 2;
        n /= 2;
    }

    // Check odd factors from 3 upwards
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            largest = i;
            n /= i;
        }
    }

    // If n is still > 1, then it's a prime factor itself
    if (n > 1) {
        largest = n;
    }

    printf("Problem 003: Largest prime factor of 600851475143 = %" PRId64 "\n", (int64_t)largest);
    return 0;
}
