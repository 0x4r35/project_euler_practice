#include <algorithm>
#include <iostream>
#include <string>

std::string add_strings(const std::string& a, const std::string& b) {
    std::string result;
    int carry = 0;
    int i = static_cast<int>(a.size()) - 1;
    int j = static_cast<int>(b.size()) - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        result.push_back(static_cast<char>('0' + (sum % 10)));
        carry = sum / 10;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    std::string numerator = "3";
    std::string denominator = "2";
    int count = 0;

    for (int i = 1; i <= 1000; i++) {
        if (numerator.size() > denominator.size()) {
            count++;
        }

        std::string next_numerator = add_strings(numerator, add_strings(denominator, denominator));
        std::string next_denominator = add_strings(numerator, denominator);
        numerator = next_numerator;
        denominator = next_denominator;
    }

    std::cout << count << '\n';
    return 0;
}
