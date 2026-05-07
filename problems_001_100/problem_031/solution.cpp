#include <iostream>
#include <vector>

int main() {
    std::vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200};
    std::vector<int> ways(201, 0);
    ways[0] = 1;
    for (int coin : coins) {
        for (int j = coin; j <= 200; ++j) {
            ways[j] += ways[j - coin];
        }
    }
    std::cout << ways[200] << "\n";
    return 0;
}
