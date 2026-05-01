/*
 * Project Euler - Problem 007
 * 10001st prime
 * https://projecteuler.net/problem=7
 *
 * Author: 0x4r35
 * Language: C
 */
#include <stdio.h>
#include <stdbool.h>

bool is_prime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    int count = 0;
    long long p = 1;
    while (count < 10001) {
        p++;
        if (is_prime(p)) {
            count++;
        }
    }
    printf("%lld\n", p);
    return 0;
}
