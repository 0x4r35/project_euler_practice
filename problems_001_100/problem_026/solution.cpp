#include <iostream>
#include <vector>

int main() {
    int max_length = 0;
    int best_d = 0;
    
    for (int d = 2; d < 1000; d++) {
        std::vector<int> remainders(d, 0);
        int value = 1;
        int position = 1; // 1-indexed to differentiate from 0 initialization
        
        while (remainders[value] == 0 && value != 0) {
            remainders[value] = position;
            value *= 10;
            value %= d;
            position++;
        }
        
        if (value != 0) {
            int cycle_length = position - remainders[value];
            if (cycle_length > max_length) {
                max_length = cycle_length;
                best_d = d;
            }
        }
    }
    
    std::cout << "The value of d < 1000 for which 1/d contains the longest recurring cycle is: " << best_d << std::endl;
    return 0;
}
