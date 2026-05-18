/*
 * Project Euler - Problem 040
 * Champernowne's Constant
 * https://projecteuler.net/problem=40
 *
 * Author: 0x4r35
 * Language: C
 *
 * Find the value of the expression: d_1 * d_10 * d_100 * d_1000 * d_10000 * d_100000 * d_1000000
 */

#include <stdio.h>

int main() {
    int targets[] = {1, 10, 100, 1000, 10000, 100000, 1000000};
    int target_count = 7;
    int product = 1;
    
    int curr_index = 0;
    int num = 1;
    int target_idx = 0;
    
    while (target_idx < target_count) {
        int target = targets[target_idx];
        
        // Find length of num
        int temp = num;
        int num_len = 0;
        while (temp > 0) {
            num_len++;
            temp /= 10;
        }
        
        if (curr_index + num_len >= target) {
            // The target digit is in this number!
            // It is the (target - curr_index)-th digit from the left (1-indexed).
            int digit_pos_from_right = num_len - (target - curr_index);
            int digit_temp = num;
            for (int i = 0; i < digit_pos_from_right; i++) {
                digit_temp /= 10;
            }
            int digit = digit_temp % 10;
            
            product *= digit;
            target_idx++;
        }
        
        curr_index += num_len;
        num++;
    }
    
    printf("%d\n", product);
    return 0;
}
