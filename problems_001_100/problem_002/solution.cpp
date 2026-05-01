/*
 * Project Euler - Problem 002
 * Even Fibonacci Numbers
 * https://projecteuler.net/problem=2
 *
 * Find the sum of the even-valued Fibonacci terms not exceeding four million.
 *
 * Author: 0x4r35
 * Language: C++
 *
 * Approach: Every 3rd Fibonacci number is even (pattern: odd, odd, EVEN).
 *           We can derive a recurrence for just the even terms:
 *           E(n) = 4 * E(n-1) + E(n-2)
 *           This skips all odd terms entirely.
 */

#include <iostream>

int main() {
    long long sum = 0;

    // Even Fibonacci recurrence: E(n) = 4*E(n-1) + E(n-2)
    // Starting values: E(1) = 2, E(2) = 8
    long long e_prev2 = 2;  // E(1) = F(3) = 2
    long long e_prev1 = 8;  // E(2) = F(6) = 8

    sum += e_prev2;
    if (e_prev1 <= 4000000) sum += e_prev1;

    while (true) {
        long long e_curr = 4 * e_prev1 + e_prev2;
        if (e_curr > 4000000) break;
        sum += e_curr;
        e_prev2 = e_prev1;
        e_prev1 = e_curr;
    }

    std::cout << "Problem 002: Sum of even Fibonacci numbers <= 4,000,000 = " << sum << std::endl;
    return 0;
}
