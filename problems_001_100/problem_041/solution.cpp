

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string digits = "7654321";
    do {
        int val = stoi(digits);
        if (is_prime(val)) {
            cout << val << "\n";
            return 0;
        }
    } while (prev_permutation(digits.begin(), digits.end()));
    
    return 0;
}
