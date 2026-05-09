#include <iostream>
#include <numeric>

int main() {
    int num_prod = 1;
    int den_prod = 1;

    for (int d = 11; d < 100; d++) {
        if (d % 10 == 0) continue;
        for (int n = 10; n < d; n++) {
            int n0 = n % 10;
            int n1 = n / 10;
            int d0 = d % 10;
            int d1 = d / 10;

            if (n0 == d1 && n * d0 == d * n1) {
                num_prod *= n;
                den_prod *= d;
            } else if (n1 == d0 && n * d1 == d * n0) {
                num_prod *= n;
                den_prod *= d;
            }
        }
    }

    std::cout << den_prod / std::gcd(num_prod, den_prod) << std::endl;
    return 0;
}
