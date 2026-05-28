#include <stdio.h>

int is_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n = 9;
    while (1) {
        if (!is_prime(n)) {
            int found = 0;
            for (int p = 2; p < n; p++) {
                if (is_prime(p)) {
                    int k = 1;
                    while (p + 2 * k * k <= n) {
                        if (p + 2 * k * k == n) {
                            found = 1;
                            break;
                        }
                        k++;
                    }
                    if (found) break;
                }
            }
            if (!found) {
                printf("%d\n", n);
                break;
            }
        }
        n += 2;
    }
    return 0;
}
