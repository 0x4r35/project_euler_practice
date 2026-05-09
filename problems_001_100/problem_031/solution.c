#include <stdio.h>

int main() {
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
    int ways[201] = {0};
    ways[0] = 1;
    for (int i = 0; i < 8; ++i) {
        for (int j = coins[i]; j <= 200; ++j) {
            ways[j] += ways[j - coins[i]];
        }
    }
    printf("%d\n", ways[200]);
    return 0;
}
