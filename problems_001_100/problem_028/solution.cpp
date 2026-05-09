#include <iostream>

int main() {
    long long sum = 1;
    for (int n = 3; n <= 1001; n += 2) {
        sum += 4LL * n * n - 6LL * n + 6;
    }
    std::cout << sum << "\n";
    return 0;
}
