/*
 * Project Euler - Problem 036
 * Double-base Palindromes
 * https://projecteuler.net/problem=36
 *
 * Author: 0x4r35
 * Language: C++
 *
 * Find the sum of all numbers less than one million which are
 * palindromic in both base 10 and base 2.
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>

using namespace std;

bool is_palindrome(const string& s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i])
            return false;
    }
    return true;
}

/* Convert integer to binary string (no leading zeros) */
string to_binary(int n) {
    if (n == 0) return "0";
    string result;
    while (n > 0) {
        result += ('0' + (n & 1));
        n >>= 1;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    long long sum = 0;

    for (int i = 1; i < 1000000; i++) {
        string dec = to_string(i);
        string bin = to_binary(i);

        if (is_palindrome(dec) && is_palindrome(bin))
            sum += i;
    }

    cout << sum << "\n";
    return 0;
}
