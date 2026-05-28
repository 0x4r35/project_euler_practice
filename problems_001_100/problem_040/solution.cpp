
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> targets = {1, 10, 100, 1000, 10000, 100000, 1000000};
    int product = 1;
    
    int curr_index = 0;
    int num = 1;
    size_t target_idx = 0;
    
    while (target_idx < targets.size()) {
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
    
    cout << product << "\n";
    return 0;
}
