/*
 * Project Euler - Problem 001
 * Multiples of 3 or 5
 * https://projecteuler.net/problem=1
 *
 * If we list all the natural numbers below 10 that are multiples of 3 or 5,
 * we get 3, 5, 6 and 9. The sum of these multiples is 23.
 * Find the sum of all the multiples of 3 or 5 below 1000.
 *
 * Author: 0x4r35
 * Language: C
 */

#include <stdio.h>

int main() {
    int sum = 0;

    for (int i = 1; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }

    printf("Problem 001: Sum of multiples of 3 or 5 below 1000 = %d\n", sum);
    return 0;
}
