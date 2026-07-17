#include <algorithm>
#include <iostream>
#include <vector>

void multiply(std::vector<int>& digits, int factor) {
    int carry = 0;
    for (int& digit : digits) {
        int product = digit * factor + carry;
        digit = product % 10;
        carry = product / 10;
    }
    while (carry > 0) {
        digits.push_back(carry % 10);
        carry /= 10;
    }
}

int digit_sum(const std::vector<int>& digits) {
    int sum = 0;
    for (int digit : digits) {
        sum += digit;
    }
    return sum;
}

int main() {
    int best = 0;

    for (int a = 1; a < 100; a++) {
        std::vector<int> value{1};
        for (int b = 1; b < 100; b++) {
            multiply(value, a);
            best = std::max(best, digit_sum(value));
        }
    }

    std::cout << best << '\n';
    return 0;
}
