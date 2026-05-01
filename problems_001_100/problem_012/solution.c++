#include <iostream>

// Function to find the number of divisors using Prime Factorization Exponents
int count_divisors(long long n) {
    int total_divisors = 1;
    
    // Factorize the number by extracting primes
    for (long long i = 2; i * i <= n; i++) {
        int exponent = 0;
        while (n % i == 0) {
            exponent++;
            n /= i;
        }
        // Multiply by (exponent + 1)
        total_divisors *= (exponent + 1);
    }
    
    // If n is not 1, then the remaining portion is itself a prime number
    if (n > 1) {
        total_divisors *= 2; // (1 + 1) for the exponent of 1
    }
    
    return total_divisors;
}

int main() {
    long long n = 1;
    int divisors = 0;

    while (true) {
        // Since n and (n+1) are coprime, we can multiply their individual divisor counts
        // We divide the even one by 2 to satisfy Tn = n(n+1)/2
        if (n % 2 == 0) {
            divisors = count_divisors(n / 2) * count_divisors(n + 1);
        } else {
            divisors = count_divisors(n) * count_divisors((n + 1) / 2);
        }

        if (divisors > 500) {
            long long triangle_num = (n * (n + 1)) / 2;
            std::cout << "The first triangle number with over 500 divisors is: " << triangle_num << std::endl;
            break;
        }
        n++;
    }

    return 0;
}