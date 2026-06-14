#include <iostream>
#include <vector>
#include <string>

int main() {
    const int limit = 1000000;
    std::vector<bool> sieve(limit, false);
    for (int i = 2; i < limit; i++) sieve[i] = true;
    for (int p = 2; p * p < limit; p++) {
        if (sieve[p]) {
            for (int i = p * p; i < limit; i += p)
                sieve[i] = false;
        }
    }

    for (int n = 56003; n < limit; n++) {
        if (!sieve[n]) continue;

        std::string s = std::to_string(n);
        int len = s.size();

        for (int mask = 1; mask < (1 << len); mask++) {
            std::vector<int> positions;
            for (int b = 0; b < len; b++) {
                if (mask & (1 << b))
                    positions.push_back(b);
            }

            char ref = s[positions[0]];
            bool all_same = true;
            for (size_t p = 1; p < positions.size(); p++) {
                if (s[positions[p]] != ref) {
                    all_same = false;
                    break;
                }
            }
            if (!all_same) continue;

            int family_count = 0;
            int smallest = 0;

            for (char d = '0'; d <= '9'; d++) {
                std::string candidate = s;
                for (int pos : positions)
                    candidate[pos] = d;

                if (candidate[0] == '0') continue;

                int val = std::stoi(candidate);
                if (val >= 2 && val < limit && sieve[val]) {
                    if (family_count == 0) smallest = val;
                    family_count++;
                }
            }

            if (family_count >= 8 && smallest == n) {
                std::cout << n << '\n';
                return 0;
            }
        }
    }

    return 0;
}
