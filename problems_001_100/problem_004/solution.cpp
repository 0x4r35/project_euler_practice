/*
 * Project Euler - Problem 004
 * Largest Palindrome Product
 * https://projecteuler.net/problem=4
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 *
 * Author: 0x4r35
 * Language: C++
 *
 * Approach: A 6-digit palindrome abccba = 100001a + 10010b + 1100c
 *           = 11 × (9091a + 910b + 100c)
 *           So the palindrome is always divisible by 11, meaning at least
 *           one of the two 3-digit factors must be divisible by 11.
 */

#include <iostream>
#include <string>
#include <algorithm>

bool isPalindrome(int n) {
    std::string s = std::to_string(n);
    std::string r = s;
    std::reverse(r.begin(), r.end());
    return s == r;
}

int main() {
    int largest = 0;

    for (int i = 999; i >= 100; i--) {
        // Since palindrome is divisible by 11, we can optimize:
        // If i is divisible by 11, j can be anything (999 down to 100)
        // If i is NOT divisible by 11, j must be divisible by 11
        int j_start, j_step;
        if (i % 11 == 0) {
            j_start = 999;
            j_step = 1;
        } else {
            // Find largest j <= i that is divisible by 11
            j_start = 990;  // largest 3-digit multiple of 11
            j_step = 11;
        }

        for (int j = j_start; j >= 100; j -= j_step) {
            int product = i * j;

            if (product <= largest) break;  // Products only get smaller from here

            if (isPalindrome(product)) {
                largest = product;
            }
        }
    }

    std::cout << "Problem 004: Largest palindrome from product of two 3-digit numbers = " << largest << std::endl;
    return 0;
}
