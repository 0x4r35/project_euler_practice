#include <stdio.h>

// Function to mathematically calculate the letter count of a number
int get_letter_count(int n) {
    // Array storing the lengths of words for 0-19
    // Index 0 is 0 because zero is not counted in numbers like 20 ("twenty", not "twenty-zero")
    int ones[] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
    
    // Array storing the lengths of tens (20, 30, 40... 90)
    int tens[] = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};
    
    if (n < 20) {
        return ones[n];
    }
    if (n < 100) {
        return tens[n / 10] + ones[n % 10];
    }
    if (n < 1000) {
        int count = ones[n / 100] + 7; // Add length of "hundred" (7)
        if (n % 100 != 0) {
            count += 3; // Add length of "and" (3)
            count += get_letter_count(n % 100); // Recursively get the rest
        }
        return count;
    }
    if (n == 1000) {
        return 11; // "one" (3) + "thousand" (8)
    }
    
    return 0;
}

int main() {
    int total_letters = 0;
    
    for (int i = 1; i <= 1000; i++) {
        total_letters += get_letter_count(i);
    }
    
    printf("Total letters used from 1 to 1000: %d\n", total_letters);
    return 0;
}