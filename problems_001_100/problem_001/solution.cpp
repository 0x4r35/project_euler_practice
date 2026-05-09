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
 * Language: C++
 *
 * Approach: Using the inclusion-exclusion principle with arithmetic series
 *           formula instead of brute force for O(1) time complexity.
 */

#include <iostream>

// Sum of multiples of n below limit using arithmetic series: n + 2n + 3n + ... = n * (1 + 2 + ... + k)
// where k = (limit - 1) / n
long long sumMultiples(int n, int limit) {
    long long k = (limit - 1) / n;
    return n * k * (k + 1) / 2;
}

int main() {
    // Inclusion-Exclusion: multiples of 3 + multiples of 5 - multiples of 15
    long long result = sumMultiples(3, 1000) + sumMultiples(5, 1000) - sumMultiples(15, 1000);

    std::cout << "Problem 001: Sum of multiples of 3 or 5 below 1000 = " << result << std::endl;
    return 0;
}
