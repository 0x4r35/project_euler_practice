#include <iostream>
#include <vector>

int main() {
    const int limit = 1000000;
    std::vector<int> omega(limit, 0);

    for (int i = 2; i < limit; ++i) {
        if (omega[i] == 0) {
            for (int j = i; j < limit; j += i) {
                omega[j]++;
            }
        }
    }

    int streak = 0;
    for (int i = 2; i < limit; ++i) {
        if (omega[i] == 4) {
            streak++;
            if (streak == 4) {
                std::cout << i - 3 << '\n';
                break;
            }
        } else {
            streak = 0;
        }
    }

    return 0;
}