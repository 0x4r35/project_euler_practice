#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate

int main() {
    std::vector<int> digits = {1}; // 1! = 1

    for (int i = 2; i <= 100; ++i) {
        int carry = 0;
        
        // Pass by reference so we directly overwrite the digit in the vector
        for (int& digit : digits) {
            int product = digit * i + carry;
            digit = product % 10;
            carry = product / 10;
        }
        
        // Push any remaining carry onto the back of the vector
        while (carry > 0) {
            digits.push_back(carry % 10);
            carry /= 10;
        }
    }

    // Safely add up all the digits
    int sum = std::accumulate(digits.begin(), digits.end(), 0);

    std::cout << "The sum of the digits in 100! is: " << sum << std::endl;
    return 0;
}