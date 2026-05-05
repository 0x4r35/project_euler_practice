#include <stdio.h>

// Helper function to calculate factorials
int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    int f = 1;
    for (int i = 2; i <= n; i++) {
        f *= i;
    }
    return f;
}

int main() {
    int available_digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int num_digits = 10;
    
    // We want the 1,000,000th permutation. 
    // We subtract 1 because our math logic is 0-indexed.
    int target = 1000000 - 1; 
    
    printf("The millionth lexicographic permutation is: ");
    
    for (int i = num_digits - 1; i >= 0; i--) {
        int fact = factorial(i);
        
        // Find the index of the next digit
        int selected_index = target / fact;
        
        // Print the selected digit
        printf("%d", available_digits[selected_index]);
        
        // Remove the selected digit from our available pool by shifting everything left
        for (int j = selected_index; j < num_digits - 1; j++) {
            available_digits[j] = available_digits[j + 1];
        }
        
        // Update the target to be the remainder for the next loop
        target = target % fact;
    }
    
    printf("\n");
    return 0;
}