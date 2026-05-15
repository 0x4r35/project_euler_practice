#include <iostream>

using namespace std;

int main() {
    int fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    int total_sum = 0;

    for (int i = 10; i <= 2540160; i++) {
        int sum = 0;
        int temp = i;
        
        while (temp > 0) {
            sum += fact[temp % 10];
            temp /= 10;
        }
        
        if (sum == i) {
            total_sum += i;
        }
    }

    cout << total_sum << "\n";
    return 0;
}
