#include <iostream>
#include <vector>
#include <numeric> // Required for std::accumulate

int main() {
    // Start our dynamic array with the number 1
    std::vector<int> digits = {1}; 

    for (int i = 0; i < 1000; ++i) {
        int carry = 0;
        
        // Pass by reference (&) so we can modify the digits directly
        for (int& digit : digits) {
            int product = digit * 2 + carry;
            digit = product % 10;
            carry = product / 10;
        }
        
        // If we overflowed our current array size, push a new digit onto the end
        if (carry > 0) {
            digits.push_back(carry);
        }
    }

    // std::accumulate easily sums up the entire vector
    int sum = std::accumulate(digits.begin(), digits.end(), 0);

    std::cout << "The sum of the digits of 2^1000 is: " << sum << std::endl;
    return 0;
}