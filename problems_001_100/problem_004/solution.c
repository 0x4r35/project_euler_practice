/*
 * Project Euler - Problem 004
 * Largest Palindrome Product
 * https://projecteuler.net/problem=4
 *
 * A palindromic number reads the same both ways. The largest palindrome
 * made from the product of two 2-digit numbers is 9009 = 91 × 99.
 * Find the largest palindrome made from the product of two 3-digit numbers.
 *
 * Author: 0x4r35
 * Language: C
 */

#include <stdio.h>

// Check if a number is a palindrome by reversing its digits
int is_palindrome(int n) {
    int original = n;
    int reversed = 0;

    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }

    return original == reversed;
}

int main() {
    int largest = 0;

    for (int i = 999; i >= 100; i--) {
        for (int j = i; j >= 100; j--) {  // j starts from i to avoid duplicate checks
            int product = i * j;

            // Early exit: if product is already smaller than our best, break inner loop
            if (product <= largest) break;

            if (is_palindrome(product)) {
                largest = product;
            }
        }
    }

    printf("Problem 004: Largest palindrome from product of two 3-digit numbers = %d\n", largest);
    return 0;
}
