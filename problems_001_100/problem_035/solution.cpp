/*
 * Project Euler - Problem 035
 * Circular Primes
 * https://projecteuler.net/problem=35
 *
 * Author: 0x4r35
 * Language: C++
 *
 * The number 197 is called a circular prime because all rotations
 * of the digits: 197, 971, 719, are themselves prime.
 * How many circular primes are there below one million?
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

const int LIMIT = 1000000;

vector<bool> build_sieve(int limit) {
    vector<bool> is_prime(limit, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= (int)sqrt(limit); i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < limit; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}

bool is_circular_prime(int n, const vector<bool>& is_prime) {
    string s = to_string(n);
    int len = s.size();

    for (int i = 0; i < len; i++) {
        // Rotate: move first char to end
        rotate(s.begin(), s.begin() + 1, s.end());
        int rotated = stoi(s);
        if (rotated >= LIMIT || !is_prime[rotated])
            return false;
    }
    return true;
}

int main() {
    vector<bool> is_prime = build_sieve(LIMIT);

    int count = 0;
    for (int i = 2; i < LIMIT; i++) {
        if (is_prime[i] && is_circular_prime(i, is_prime))
            count++;
    }

    cout << count << "\n";
    return 0;
}
