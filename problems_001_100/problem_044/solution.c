/*
 * Project Euler - Problem 044
 * Pentagon numbers
 * https://projecteuler.net/problem=44
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

long long pentagonal(long long n) {
    return n * (3 * n - 1) / 2;
}

int main() {
    int found = 0;
    long long k = 2;
    long long result = 0;
    
    while (!found) {
        long long pk = pentagonal(k);
        for (long long j = k - 1; j >= 1; --j) {
            long long pj = pentagonal(j);
            if (is_pentagonal(pk - pj) && is_pentagonal(pk + pj)) {
                result = pk - pj;
                found = 1;
                break;
            }
        }
        k++;
    }
    
    printf("%lld\n", result);
    return 0;
}
