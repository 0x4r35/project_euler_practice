#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num_prod = 1;
    int den_prod = 1;

    for (int i = 10; i < 100; i++) {
        for (int j = i + 1; j < 100; j++) {
            int n1 = i / 10;
            int n0 = i % 10;
            int d1 = j / 10;
            int d0 = j % 10;

            if (n0 == 0 && d0 == 0) continue;

            if (n0 == d1 && d0 != 0 && n1 * j == i * d0) {
                num_prod *= i;
                den_prod *= j;
            } else if (n1 == d0 && d1 != 0 && n0 * j == i * d1) {
                num_prod *= i;
                den_prod *= j;
            }
        }
    }

    int div = gcd(num_prod, den_prod);
    printf("%d\n", den_prod / div);

    return 0;
}
