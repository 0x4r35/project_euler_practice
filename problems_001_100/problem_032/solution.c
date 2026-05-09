#include <stdio.h>
#include <stdbool.h>

// Checks if the concatenation of a, b, and c contains digits 1-9 exactly once
bool is_pandigital(int a, int b, int c) {
    int mask = 0;
    int count = 0;
    int numbers[3] = {a, b, c};

    for (int i = 0; i < 3; i++) {
        int num = numbers[i];
        while (num > 0) {
            int digit = num % 10;
            // 0 is not allowed in 1-9 pandigital
            if (digit == 0) return false;
            // If the bit for this digit is already set, it's a duplicate
            if (mask & (1 << digit)) return false; 
            
            mask |= (1 << digit);
            count++;
            num /= 10;
        }
    }
    // We must have exactly 9 digits, and the mask must be 1111111110 in binary (1022)
    return count == 9 && mask == 1022; 
}

int main() {
    bool seen[10000] = {false};
    long long sum = 0;

    // Based on digit math, multiplicand 'a' can be 1 or 2 digits.
    // (It cannot be 1, because 1 * b = b would duplicate digits).
    for (int a = 2; a <= 99; a++) {
        int b_start = (a < 10) ? 1234 : 123;
        int b_end = 10000 / a + 1;
        
        for (int b = b_start; b <= b_end; b++) {
            int c = a * b;
            
            // Product must be strictly 4 digits
            if (c >= 10000) continue;
            
            if (!seen[c] && is_pandigital(a, b, c)) {
                seen[c] = true;
                sum += c;
            }
        }
    }

    printf("%lld\n", sum);
    return 0;
}