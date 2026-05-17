/*
 * Project Euler - Problem 038
 * Pandigital Multiples
 * https://projecteuler.net/problem=38
 *
 * Author: 0x4r35
 * Language: C++
 *
 * What is the largest 1 to 9 pandigital 9-digit number that can be
 * formed as the concatenated product of an integer with (1, 2, ..., n)
 * where n > 1?
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

bool is_pandigital(const string& s) {
    if (s.size() != 9) return false;

    set<char> digits(s.begin(), s.end());
    return digits.size() == 9 && digits.find('0') == digits.end();
}

int main() {
    int largest = 0;

    /*
     * We need n > 1, so the integer must produce at least 2 products.
     * For n=2: integer * 1 concatenated with integer * 2 = 9 digits.
     * A 4-digit number * (1,2) gives 4+5 = 9 digits (possible).
     * So we check integers up to 9999.
     */
    for (int i = 1; i <= 9999; i++) {
        string concat;

        for (int n = 1; concat.size() < 9; n++) {
            concat += to_string(i * n);
        }

        if (concat.size() == 9 && is_pandigital(concat)) {
            int value = stoi(concat);
            largest = max(largest, value);
        }
    }

    cout << largest << "\n";
    return 0;
}
