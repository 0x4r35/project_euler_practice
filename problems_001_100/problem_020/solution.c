#include <stdio.h>

#define MAX_DIGITS 200

int main() {
    // Initialize an array of 200 zeros
    int digits[MAX_DIGITS] = {0}; 
    
    // Base case: 1! = 1
    digits[0] = 1; 
    int num_digits = 1;

    // Multiply by every number from 2 to 100
    for (int i = 2; i <= 100; i++) {
        int carry = 0;
        
        // Multiply each digit in the array by 'i'
        for (int j = 0; j < num_digits; j++) {
            int product = digits[j] * i + carry;
            digits[j] = product % 10; // Store the ones digit
            carry = product / 10;     // Carry the rest to the next place
        }
        
        // If there's carry left after multiplying the highest digit, extend the array length
        while (carry > 0) {
            digits[num_digits] = carry % 10;
            carry /= 10;
            num_digits++;
        }
    }

    // Sum the array
    int sum = 0;
    for (int i = 0; i < num_digits; i++) {
        sum += digits[i];
    }

    printf("The sum of the digits in 100! is: %d\n", sum);
    return 0;
}