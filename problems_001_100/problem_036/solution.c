/*
 * Project Euler - Problem 036
 * Double-base Palindromes
 * https://projecteuler.net/problem=36
 *
 * Author: 0x4r35
 * Language: C
 *
 * Find the sum of all numbers less than one million which are
 * palindromic in both base 10 and base 2.
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* Check if string s of length len is a palindrome */
bool is_palindrome_str(char *s, int len) {
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - 1 - i])
            return false;
    }
    return true;
}

/* Check if n is a palindrome in base 10 */
bool is_palindrome_base10(int n) {
    char buf[20];
    int len = sprintf(buf, "%d", n);
    return is_palindrome_str(buf, len);
}

/* Check if n is a palindrome in base 2 */
bool is_palindrome_base2(int n) {
    char bits[25];
    int len = 0;

    int temp = n;
    while (temp > 0) {
        bits[len++] = '0' + (temp & 1);
        temp >>= 1;
    }

    return is_palindrome_str(bits, len);
}

int main() {
    long sum = 0;

    for (int i = 1; i < 1000000; i++) {
        if (is_palindrome_base10(i) && is_palindrome_base2(i))
            sum += i;
    }

    printf("%ld\n", sum);
    return 0;
}
