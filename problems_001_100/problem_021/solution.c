#include <stdio.h>
#include <math.h>

// Function to calculate the sum of proper divisors of n
int sum_proper_divisors(int n) {
    if (n < 2) return 0;
    
    int sum = 1; // 1 is always a proper divisor
    int limit = (int)sqrt(n);
    
    for (int i = 2; i <= limit; i++) {
        if (n % i == 0) {
            sum += i;
            // Add the paired divisor if it's different from i
            if (i != n / i) {
                sum += n / i;
            }
        }
    }
    return sum;
}

int main() {
    int total_amicable_sum = 0;
    const int LIMIT = 10000;

    for (int a = 2; a < LIMIT; a++) {
        int b = sum_proper_divisors(a);
        
        // Check if b is greater than a to prevent double counting
        // Also check if they form an amicable pair
        if (b > a && b < LIMIT) {
            if (sum_proper_divisors(b) == a) {
                printf("Found Amicable Pair: %d and %d\n", a, b);
                total_amicable_sum += a + b;
            }
        } else if (b > a && b >= LIMIT) {
            // Edge case: if b >= 10000, we still need to check if it pairs back to a
             if (sum_proper_divisors(b) == a) {
                  // Only add 'a' to the sum since the problem asks for amicable numbers *under* 10000.
                  // Wait, the prompt says "Evaluate the sum of all the amicable numbers under 10000".
                  // This means if a < 10000 and b > 10000, we only add 'a'. 
                  // Let's adjust the logic slightly to perfectly match the prompt.
             }
        }
    }
    
    // Let's refine the logic to strictly sum individual numbers < 10000 that belong to *any* amicable pair.
    total_amicable_sum = 0;
    for (int i = 2; i < LIMIT; i++) {
        int possible_pair = sum_proper_divisors(i);
        if (possible_pair != i && sum_proper_divisors(possible_pair) == i) {
            total_amicable_sum += i;
        }
    }

    printf("Sum of all amicable numbers under 10000 is: %d\n", total_amicable_sum);
    return 0;
}