#include <iostream>
#include <vector>

int main() {
    const int LIMIT = 28123;
    
    std::vector<int> div_sums(LIMIT + 1, 0);
    std::vector<int> abundant;
    std::vector<bool> can_be_written(LIMIT + 1, false);

    // 1. Sieve method for proper divisors
    for (int i = 1; i <= LIMIT / 2; ++i) {
        for (int j = i * 2; j <= LIMIT; j += i) {
            div_sums[j] += i;
        }
    }

    // 2. Collect abundant numbers
    for (int i = 1; i <= LIMIT; ++i) {
        if (div_sums[i] > i) {
            abundant.push_back(i);
        }
    }

    // 3. Mark sums of two abundant numbers
    for (size_t i = 0; i < abundant.size(); ++i) {
        for (size_t j = i; j < abundant.size(); ++j) {
            int sum = abundant[i] + abundant[j];
            if (sum <= LIMIT) {
                can_be_written[sum] = true;
            } else {
                break;
            }
        }
    }

    // 4. Calculate final total
    long long final_sum = 0;
    for (int i = 1; i <= LIMIT; ++i) {
        if (!can_be_written[i]) {
            final_sum += i;
        }
    }

    std::cout << "Sum of non-abundant sums: " << final_sum << std::endl;
    return 0;
}