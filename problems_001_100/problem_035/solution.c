/*
 * Project Euler - Problem 035
 * Circular Primes
 * https://projecteuler.net/problem=35
 *
 * Author: 0x4r35
 * Language: C
 *
 * The number 197 is called a circular prime because all rotations
 * of the digits: 197, 971, 719, are themselves prime.
 * How many circular primes are there below one million?
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

/* Count the number of digits in n */
int num_digits(int n) {
    int count = 0;
    while (n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

/* Rotate n by moving the leading digit to the end */
int rotate(int n, int digits) {
    int power = 1;
    for (int i = 1; i < digits; i++)
        power *= 10;

    int leading = n / power;
    return (n % power) * 10 + leading;
}

/* Check if all rotations of n are prime */
bool is_circular_prime(int n) {
    int digits = num_digits(n);
    int rotated = n;

    for (int i = 0; i < digits; i++) {
        if (rotated < 0 || rotated >= LIMIT || !sieve[rotated])
            return false;
        rotated = rotate(rotated, digits);
    }
    return true;
}

int main() {
    build_sieve();

    int count = 0;
    for (int i = 2; i < LIMIT; i++) {
        if (is_circular_prime(i))
            count++;
    }

    printf("%d\n", count);
    return 0;
}
