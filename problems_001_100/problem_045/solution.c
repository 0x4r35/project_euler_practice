/*
 * Project Euler - Problem 045
 * Triangular, pentagonal, and hexagonal
 * https://projecteuler.net/problem=45
 *
 * Author: 0x4r35
 * Language: C
 */

#include <stdio.h>
#include <math.h>

int is_pentagonal(long long n) {
    double val = (sqrt(24.0 * n + 1.0) + 1.0) / 6.0;
    return val == (long long)val;
}

int main() {
    long long m = 144;
    while (1) {
        long long hex = m * (2 * m - 1);
        if (is_pentagonal(hex)) {
            printf("%lld\n", hex);
            break;
        }
        m++;
    }
    return 0;
}
