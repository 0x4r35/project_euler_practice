#include <iostream>
#include <algorithm>
#include <string>

std::string sorted_digits(int n) {
    std::string s = std::to_string(n);
    std::sort(s.begin(), s.end());
    return s;
}

int main() {
    for (int x = 1; ; x++) {
        std::string base = sorted_digits(x);
        bool valid = true;
        for (int m = 2; m <= 6; m++) {
            if (sorted_digits(x * m) != base) {
                valid = false;
                break;
            }
        }
        if (valid) {
            std::cout << x << '\n';
            return 0;
        }
    }
    return 0;
}
