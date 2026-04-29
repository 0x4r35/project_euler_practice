/*
 * Project Euler - Problem 003
 * Largest Prime Factor
 * https://projecteuler.net/problem=3
 *
 * What is the largest prime factor of the number 600851475143?
 *
 * Author: 0x4r35
 * Language: C++
 *
 * Approach: Trial division with optimization — only check up to sqrt(n).
 *           After dividing out all small factors, if n > 1, it IS the
 *           largest prime factor. This works because a composite number
 *           must have at least one factor <= sqrt(n).
 */

#include <iostream>
#include <cmath>

int main() {
    long long n = 600851475143LL;
    long long largest_prime = -1;

    // Remove all factors of 2
    while (n % 2 == 0) {
        largest_prime = 2;
        n /= 2;
    }

    // Try odd divisors from 3 to sqrt(n)
    for (long long i = 3; i <= static_cast<long long>(std::sqrt(n)); i += 2) {
        while (n % i == 0) {
            largest_prime = i;
            n /= i;
        }
    }

    // If n is still greater than 1, then it's the largest prime factor
    if (n > 1) {
        largest_prime = n;
    }

    std::cout << "Problem 003: Largest prime factor of 600851475143 = " << largest_prime << std::endl;
    return 0;
}
