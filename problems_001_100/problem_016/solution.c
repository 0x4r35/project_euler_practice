#include <stdio.h>

#define MAX_DIGITS 400

int main() {
    // Initialize an array of 400 zeros
    int digits[MAX_DIGITS] = {0}; 
    
    // Start with 2^0 = 1
    digits[0] = 1; 
    int num_digits = 1; // Keep track of how long our number currently is

    // Multiply by 2, one thousand times
    for (int i = 0; i < 1000; i++) {
        int carry = 0;
        
        // Go through each digit currently in our array
        for (int j = 0; j < num_digits; j++) {
            int product = digits[j] * 2 + carry;
            digits[j] = product % 10; // Keep only the ones digit
            carry = product / 10;     // Carry the tens digit
        }
        
        // If there's still a carry left over, add a new digit to our array!
        while (carry > 0) {
            digits[num_digits] = carry % 10;
            carry /= 10;
            num_digits++;
        }
    }

    // Sum all the digits in the array
    int sum = 0;
    for (int i = 0; i < num_digits; i++) {
        sum += digits[i];
    }

    printf("The sum of the digits of 2^1000 is: %d\n", sum);
    return 0;
}