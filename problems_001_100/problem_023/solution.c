#include <stdio.h>
#include <stdbool.h>

#define LIMIT 28123

// Global arrays to prevent stack overflow
int div_sums[LIMIT + 1] = {0};
int abundant[LIMIT];
bool can_be_written[LIMIT + 1] = {false};

int main() {
    // 1. Sieve method to calculate the sum of proper divisors efficiently
    for (int i = 1; i <= LIMIT / 2; i++) {
        for (int j = i * 2; j <= LIMIT; j += i) {
            div_sums[j] += i;
        }
    }

    // 2. Collect all abundant numbers
    int ab_count = 0;
    for (int i = 1; i <= LIMIT; i++) {
        if (div_sums[i] > i) {
            abundant[ab_count++] = i;
        }
    }

    // 3. Mark all possible sums of two abundant numbers
    for (int i = 0; i < ab_count; i++) {
        for (int j = i; j < ab_count; j++) {
            int sum = abundant[i] + abundant[j];
            if (sum <= LIMIT) {
                can_be_written[sum] = true;
            } else {
                // Since the array is sorted, any further 'j' will also exceed the limit
                break; 
            }
        }
    }

    // 4. Sum the numbers that cannot be written
    long long final_sum = 0;
    for (int i = 1; i <= LIMIT; i++) {
        if (!can_be_written[i]) {
            final_sum += i;
        }
    }

    printf("Sum of non-abundant sums: %lld\n", final_sum);
    return 0;
}