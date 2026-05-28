/*
 * Project Euler - Problem 037
 * Truncatable Primes
 * https://projecteuler.net/problem=37
 *
 * Author: 0x4r35
 * Language: C++
 *
 * Find the sum of the only eleven primes that are both truncatable
 * from left to right and right to left.
 * NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

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

bool is_right_truncatable(int n, const vector<bool>& is_prime) {
    while (n > 0) {
        if (!is_prime[n]) return false;
        n /= 10;
    }
    return true;
}

bool is_left_truncatable(int n, const vector<bool>& is_prime) {
    string s = to_string(n);
    for (size_t i = 0; i < s.size(); i++) {
        int truncated = stoi(s.substr(i));
        if (!is_prime[truncated]) return false;
    }
    return true;
}

int main() {
    vector<bool> is_prime = build_sieve(LIMIT);

    long long sum = 0;
    int count = 0;

    /* Single digit primes (2, 3, 5, 7) are excluded */
    for (int i = 10; i < LIMIT && count < 11; i++) {
        if (is_prime[i] && is_right_truncatable(i, is_prime) && is_left_truncatable(i, is_prime)) {
            sum += i;
            count++;
        }
    }

    cout << sum << "\n";
    return 0;
}
