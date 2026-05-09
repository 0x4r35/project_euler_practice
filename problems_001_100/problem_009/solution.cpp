/*
 * Project Euler - Problem 009
 * Special Pythagorean triplet
 * https://projecteuler.net/problem=9
 *
 * Author: 0x4r35
 * Language: C++
 */
#include <iostream>

int main() {
    for (int a = 1; a < 1000; a++) {
        for (int b = a + 1; b < 1000; b++) {
            int c = 1000 - a - b;
            if (a * a + b * b == c * c) {
                std::cout << a * b * c << std::endl;
                return 0;
            }
        }
    }
    return 0;
}
