#include <iostream>
#include <vector>

int main() {
    const int limit = 1000000;
    std::vector<bool> is_prime(limit, true);
    is_prime[0] = is_prime[1] = false;

    for (int p = 2; p * p < limit; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i < limit; i += p) {
                is_prime[i] = false;
            }
        }
    }

    std::vector<int> primes;
    for (int i = 0; i < limit; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    std::vector<long long> prime_sums(primes.size() + 1, 0);
    for (size_t i = 0; i < primes.size(); ++i) {
        prime_sums[i + 1] = prime_sums[i] + primes[i];
    }

    int max_length = 0;
    long long max_prime = 0;

    for (size_t i = 0; i < primes.size(); ++i) {
        for (size_t j = i + max_length + 1; j <= primes.size(); ++j) {
            long long sum = prime_sums[j] - prime_sums[i];
            if (sum >= limit) break;
            
            if (is_prime[sum]) {
                int length = j - i;
                if (length > max_length) {
                    max_length = length;
                    max_prime = sum;
                }
            }
        }
    }

    std::cout << max_prime << '\n';

    return 0;
}