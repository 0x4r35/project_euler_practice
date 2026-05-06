#include <stdio.h>

#define MAX_DIGITS 1005

int main() {
    int f1[MAX_DIGITS] = {0};
    int f2[MAX_DIGITS] = {0};
    int temp[MAX_DIGITS] = {0};
    
    f1[0] = 1; // F_1 = 1
    f2[0] = 1; // F_2 = 1
    
    int index = 2; // We start tracking from F_2
    int num_digits = 1;
    
    while (num_digits < 1000) {
        int carry = 0;
        for (int i = 0; i < num_digits; i++) {
            int sum = f1[i] + f2[i] + carry;
            temp[i] = sum % 10;
            carry = sum / 10;
        }
        
        if (carry > 0) {
            temp[num_digits] = carry;
            num_digits++;
        }
        
        for (int i = 0; i < num_digits; i++) {
            f1[i] = f2[i];
            f2[i] = temp[i];
        }
        
        index++;
    }
    
    printf("The index of the first term in the Fibonacci sequence to contain 1000 digits is: %d\n", index);
    return 0;
}
