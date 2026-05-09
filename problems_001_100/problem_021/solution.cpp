#include <iostream>
#include <cmath>

int sum_proper_divisors(int n) {
    if (n <= 1) return 0;
    
    int sum = 1;
    int limit = static_cast<int>(std::sqrt(n));
    
    for (int i = 2; i <= limit; ++i) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) {
                sum += n / i;
            }
        }
    }
    return sum;
}

int main() {
    int amicable_sum = 0;
    const int LIMIT = 10000;

    for (int a = 2; a < LIMIT; ++a) {
        int b = sum_proper_divisors(a);
        
        // To be amicable: d(a) = b, d(b) = a, and a != b.
        // We only check if 'a' is part of an amicable pair.
        if (a != b && sum_proper_divisors(b) == a) {
            amicable_sum += a;
        }
    }

    std::cout << "Sum of all amicable numbers under 10000 is: " << amicable_sum << std::endl;
    return 0;
}