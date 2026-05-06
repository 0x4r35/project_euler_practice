#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int max_primes = 0;
    int best_a = 0;
    int best_b = 0;
    
    // b must be positive and prime because for n=0, n^2 + an + b = b, which must be prime.
    for (int b = 2; b <= 1000; b++) {
        if (!is_prime(b)) continue;
        
        for (int a = -999; a < 1000; a++) {
            int n = 0;
            while (true) {
                int val = n * n + a * n + b;
                if (!is_prime(val)) {
                    break;
                }
                n++;
            }
            
            if (n > max_primes) {
                max_primes = n;
                best_a = a;
                best_b = b;
            }
        }
    }
    
    printf("The product of the coefficients a and b is: %d\n", best_a * best_b);
    return 0;
}
