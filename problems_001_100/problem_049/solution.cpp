#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool are_permutations(int a, int b, int c) {
    std::string s1 = std::to_string(a);
    std::string s2 = std::to_string(b);
    std::string s3 = std::to_string(c);
    
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());
    std::sort(s3.begin(), s3.end());
    
    return (s1 == s2 && s2 == s3);
}

int main() {
    const int limit = 10000;
    std::vector<bool> is_prime(limit, true);
    is_prime[0] = is_prime[1] = false;

    for (int p = 2; p * p < limit; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i < limit; i += p) {
                is_prime[i] = false;
            }
        }
    }

    for (int i = 1000; i < 10000; ++i) {
        if (!is_prime[i] || i == 1487) continue;

        for (int step = 1; i + 2 * step < 10000; ++step) {
            int j = i + step;
            int k = j + step;

            if (is_prime[j] && is_prime[k]) {
                if (are_permutations(i, j, k)) {
                    std::cout << i << j << k << '\n';
                    return 0;
                }
            }
        }
    }

    return 0;
}