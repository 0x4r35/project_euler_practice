#include <iostream>
#include <vector>

using namespace std;

// Checks if the concatenation of a, b, and c contains digits 1-9 exactly once
bool is_pandigital(int a, int b, int c) {
    int mask = 0;
    int count = 0;
    int numbers[3] = {a, b, c};

    for (int i = 0; i < 3; i++) {
        int num = numbers[i];
        while (num > 0) {
            int digit = num % 10;
            if (digit == 0) return false;
            if (mask & (1 << digit)) return false; 
            
            mask |= (1 << digit);
            count++;
            num /= 10;
        }
    }
    return count == 9 && mask == 1022; 
}

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<bool> seen(10000, false);
    long long sum = 0;

    for (int a = 2; a <= 99; a++) {
        int b_start = (a < 10) ? 1234 : 123;
        int b_end = 10000 / a + 1;
        
        for (int b = b_start; b <= b_end; b++) {
            int c = a * b;
            
            if (c >= 10000) continue;
            
            if (!seen[c] && is_pandigital(a, b, c)) {
                seen[c] = true;
                sum += c;
            }
        }
    }

    cout << sum << "\n";
    return 0;
}