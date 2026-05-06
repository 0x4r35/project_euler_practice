#include <iostream>
#include <vector>

int main() {
    std::vector<int> f1 = {1};
    std::vector<int> f2 = {1};
    
    int index = 2;
    
    while (f2.size() < 1000) {
        std::vector<int> next_f;
        int carry = 0;
        size_t size = f2.size();
        
        for (size_t i = 0; i < size; i++) {
            int val1 = i < f1.size() ? f1[i] : 0;
            int sum = val1 + f2[i] + carry;
            next_f.push_back(sum % 10);
            carry = sum / 10;
        }
        
        if (carry > 0) {
            next_f.push_back(carry);
        }
        
        f1 = f2;
        f2 = next_f;
        index++;
    }
    
    std::cout << "The index of the first term in the Fibonacci sequence to contain 1000 digits is: " << index << std::endl;
    return 0;
}
