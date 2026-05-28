#include <iostream>

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n = 9;
    while (true) {
        if (!is_prime(n)) {
            bool found = false;
            for (int p = 2; p < n; p++) {
                if (is_prime(p)) {
                    int k = 1;
                    while (p + 2 * k * k <= n) {
                        if (p + 2 * k * k == n) {
                            found = true;
                            break;
                        }
                        k++;
                    }
                    if (found) break;
                }
            }
            if (!found) {
                std::cout << n << "\n";
                break;
            }
        }
        n += 2;
    }
    return 0;
}
