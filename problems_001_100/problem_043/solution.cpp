/*
 * Project Euler - Problem 043
 * Sub-string divisibility
 * https://projecteuler.net/problem=43
 *
 * Author: 0x4r35
 * Language: C++
 */

#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s = "0123456789";
    long long sum = 0;
    int primes[] = {2, 3, 5, 7, 11, 13, 17};
    
    do {
        bool valid = true;
        for (int i = 0; i < 7; ++i) {
            int num = std::stoi(s.substr(i + 1, 3));
            if (num % primes[i] != 0) {
                valid = false;
                break;
            }
        }
        
        if (valid) {
            sum += std::stoll(s);
        }
    } while (std::next_permutation(s.begin(), s.end()));
    
    std::cout << sum << std::endl;
    return 0;
}
