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

int main() {
    int total = 0;

    for (int base = 1; base <= 9; base++) {
        std::vector<int> value{1};

        for (int exponent = 1;; exponent++) {
            multiply(value, base);

            if (static_cast<int>(value.size()) == exponent) {
                total++;
            }
            if (static_cast<int>(value.size()) < exponent) {
                break;
            }
        }
    }

    std::cout << total << '\n';
    return 0;
}
