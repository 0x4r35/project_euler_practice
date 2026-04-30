/*
 * Project Euler - Problem 010
 * Summation of primes
 * https://projecteuler.net/problem=10
 *
 * Author: 0x4r35
 * Language: C++
 */
#include <iostream>
#include <vector>

const int LIMIT = 2000000;

int main() {
    std::vector<bool> sieve(LIMIT, false);
    long long sum = 0;
    for (int p = 2; p < LIMIT; p++) {
        if (!sieve[p]) {
            sum += p;
            for (long long i = (long long)p * p; i < LIMIT; i += p) {
                sieve[i] = true;
            }
        }
    }
    std::cout << sum << std::endl;
    return 0;
}
