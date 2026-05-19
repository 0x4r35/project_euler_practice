/*
 * Project Euler - Problem 044
 * Pentagon numbers
 * https://projecteuler.net/problem=44
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

long long pentagonal(long long n) {
    return n * (3 * n - 1) / 2;
}

int main() {
    bool found = false;
    long long k = 2; // start from 2
    long long result = 0;
    
    while (!found) {
        long long pk = pentagonal(k);
        for (long long j = k - 1; j >= 1; --j) {
            long long pj = pentagonal(j);
            if (is_pentagonal(pk - pj) && is_pentagonal(pk + pj)) {
                result = pk - pj;
                found = true;
                break;
            }
        }
        k++;
    }
    
    std::cout << result << std::endl;
    return 0;
}
