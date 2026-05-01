/*
 * Project Euler - Problem 005
 * Smallest Multiple
 * https://projecteuler.net/problem=5
 *
 * 2520 is the smallest number that can be divided by each of the numbers
 * from 1 to 10 without any remainder.
 * What is the smallest positive number that is evenly divisible by all
 * of the numbers from 1 to 20?
 *
 * Author: 0x4r35
 * Language: C
 */

#include <stdio.h>

// Greatest Common Divisor using Euclidean algorithm
long gcd(long a, long b) {
    while (b != 0) {
        long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Least Common Multiple
long lcm(long a, long b) {
    return a / gcd(a, b) * b;  // Divide first to prevent overflow
}

int main() {
    long result = 1;

    for (int i = 2; i <= 20; i++) {
        result = lcm(result, i);
    }

    printf("Problem 005: Smallest number divisible by 1 through 20 = %ld\n", result);
    return 0;
}
