#include <stdio.h>

int gcd(int a, int b) {
    while (b) {
        a %= b;
        int temp = a;
        a = b;
        b = temp;
    }
    return a;
}

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

    printf("%d\n", den_prod / gcd(num_prod, den_prod));
    return 0;
}

