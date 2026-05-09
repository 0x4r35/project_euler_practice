/*
 * Project Euler - Problem 005
 * Smallest Multiple
 * https://projecteuler.net/problem=5
 *
 * What is the smallest positive number that is evenly divisible
 * by all of the numbers from 1 to 20?
 *
 * Author: 0x4r35
 * Language: C++
 *
 * Approach: The answer is LCM(1, 2, 3, ..., 20).
 *           We can also think of it as: for each prime p <= 20,
 *           include p^k where p^k <= 20 < p^(k+1).
 *           2^4=16, 3^2=9, 5, 7, 11, 13, 17, 19
 *           = 16 * 9 * 5 * 7 * 11 * 13 * 17 * 19
 */

#include <iostream>

// GCD using Euclidean algorithm
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// LCM using GCD
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int main() {
    long long result = 1;

    for (int i = 2; i <= 20; i++) {
        result = lcm(result, static_cast<long long>(i));
    }

    std::cout << "Problem 005: Smallest number divisible by 1 through 20 = " << result << std::endl;

    // Verification using prime factorization approach
    // 2^4 * 3^2 * 5 * 7 * 11 * 13 * 17 * 19
    long long verify = 16LL * 9 * 5 * 7 * 11 * 13 * 17 * 19;
    std::cout << "Verification (prime factorization): " << verify << std::endl;

    return 0;
}
