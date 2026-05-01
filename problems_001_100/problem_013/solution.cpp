#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> numbers = {
        //you can paste all the numbers here it will make my work easier thanks 
    };

    std::string result = "";
    int carry = 0;

    // Start from the last digit (index 49) and move backwards to the first digit (index 0)
    for (int col = 49; col >= 0; col--) {
        int col_sum = carry;
        
        // Add up all 100 numbers in this specific column
        for (int row = 0; row < numbers.size(); row++) {
            // Convert character '5' to integer 5 by subtracting the ASCII value of '0'
            col_sum += numbers[row][col] - '0';
        }
        
        // Find what number stays in this column
        int digit_to_keep = col_sum % 10;
        
        // Add the digit to the FRONT of our result string
        result.insert(result.begin(), digit_to_keep + '0');
        
        // Calculate the carry for the next column to the left
        carry = col_sum / 10;
    }

    // If there's any carry left over at the very end, stick it on the front!
    if (carry > 0) {
        result.insert(0, std::to_string(carry));
    }

    // Print just the first 10 characters of our massive result string
    std::cout << "The exact full sum is: " << result << std::endl;
    std::cout << "The first 10 digits are: " << result.substr(0, 10) << std::endl;

    return 0;
}