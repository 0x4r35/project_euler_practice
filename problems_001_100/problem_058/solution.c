#include <stdio.h>

int is_prime(long long n) {
    if (n < 2) return 0;
    if (n == 2 || n == 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;

    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int prime_count = 0;
    int diagonal_count = 1;

    for (long long side = 3; ; side += 2) {
        long long square = side * side;
        long long step = side - 1;

        for (int k = 0; k < 4; k++) {
            if (is_prime(square - k * step)) {
                prime_count++;
            }
        }

        diagonal_count += 4;
        if (prime_count * 10 < diagonal_count) {
            printf("%lld\n", side);
            break;
        }
    }

    return 0;
}
