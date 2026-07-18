#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <string>

struct Group {
    int count = 0;
    long long smallest = LLONG_MAX;
};

std::string signature(long long n) {
    std::string digits = std::to_string(n);
    std::sort(digits.begin(), digits.end());
    return digits;
}

long long best_exact_group(const std::map<std::string, Group>& groups) {
    long long best = LLONG_MAX;

    for (const auto& entry : groups) {
        const Group& group = entry.second;
        if (group.count == 5 && group.smallest < best) {
            best = group.smallest;
        }
    }

    return best;
}

int main() {
    std::map<std::string, Group> groups;
    int current_digits = 1;

    for (long long n = 1;; n++) {
        long long cube = n * n * n;
        int digits = static_cast<int>(std::to_string(cube).size());

        if (digits != current_digits) {
            long long best = best_exact_group(groups);
            if (best != LLONG_MAX) {
                std::cout << best << '\n';
                return 0;
            }

            groups.clear();
            current_digits = digits;
        }

        Group& group = groups[signature(cube)];
        group.count++;
        group.smallest = std::min(group.smallest, cube);
    }
}
