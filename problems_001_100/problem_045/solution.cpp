/*
 * Project Euler - Problem 045
 * Triangular, pentagonal, and hexagonal
 * https://projecteuler.net/problem=45
 *
 * Author: 0x4r35
 * Language: C++
 */

#include <iostream>
#include <cmath>

bool is_pentagonal(long long n) {
    double val = (std::sqrt(24.0 * n + 1.0) + 1.0) / 6.0;
    return val == static_cast<long long>(val);
}

int main() {
    long long m = 144;
    while (true) {
        long long hex = m * (2 * m - 1);
        if (is_pentagonal(hex)) {
            std::cout << hex << std::endl;
            break;
        }
        m++;
    }
    return 0;
}
