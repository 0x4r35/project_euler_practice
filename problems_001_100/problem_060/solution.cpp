#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

const int LIMIT = 10000;

std::vector<int> primes;
std::vector<int> trial_primes;
std::vector<std::vector<int>> compat;
std::vector<int> chosen;
int best_sum = INT_MAX;

void build_primes() {
    std::vector<bool> is_prime(LIMIT + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int p = 2; p * p <= LIMIT; p++) {
        if (is_prime[p]) {
            for (int m = p * p; m <= LIMIT; m += p) {
                is_prime[m] = false;
            }
        }
    }

    for (int i = 2; i <= LIMIT; i++) {
        if (is_prime[i]) {
            trial_primes.push_back(i);
            if (i != 2 && i != 5) {
                primes.push_back(i);
            }
        }
    }
}

long long concat(int a, int b) {
    int pow10 = 10;
    while (pow10 <= b) {
        pow10 *= 10;
    }
    return static_cast<long long>(a) * pow10 + b;
}

bool is_prime_long(long long n) {
    if (n < 2) return false;
    for (long long p : trial_primes) {
        if (p * p > n) break;
        if (n % p == 0) {
            return n == p;
        }
    }
    return true;
}

bool compatible(int i, int j) {
    int a = std::min(i, j);
    int b = std::max(i, j);

    if (compat[a][b] == -1) {
        compat[a][b] = is_prime_long(concat(primes[a], primes[b])) &&
                       is_prime_long(concat(primes[b], primes[a]));
    }

    return compat[a][b] == 1;
}

void search(int start, int depth, int sum) {
    if (depth == 5) {
        best_sum = std::min(best_sum, sum);
        return;
    }

    for (int i = start; i < static_cast<int>(primes.size()); i++) {
        if (sum + primes[i] * (5 - depth) >= best_sum) {
            break;
        }

        bool ok = true;
        for (int index : chosen) {
            if (!compatible(index, i)) {
                ok = false;
                break;
            }
        }
        if (!ok) continue;

        chosen.push_back(i);
        search(i + 1, depth + 1, sum + primes[i]);
        chosen.pop_back();
    }
}

int main() {
    build_primes();
    compat.assign(primes.size(), std::vector<int>(primes.size(), -1));

    search(0, 0, 0);
    std::cout << best_sum << '\n';
    return 0;
}
