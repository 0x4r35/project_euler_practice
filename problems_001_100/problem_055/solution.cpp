#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

std::string add_strings(const std::string& a, const std::string& b) {
    std::string result;
    int carry = 0;
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        result.push_back('0' + sum % 10);
        carry = sum / 10;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

bool is_palindrome(const std::string& s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) return false;
    }
    return true;
}

int main() {
    int count = 0;
    for (int n = 1; n < 10000; n++) {
        std::string val = std::to_string(n);
        bool lychrel = true;
        for (int i = 0; i < 50; i++) {
            std::string rev = val;
            std::reverse(rev.begin(), rev.end());
            val = add_strings(val, rev);
            if (is_palindrome(val)) {
                lychrel = false;
                break;
            }
        }
        if (lychrel) count++;
    }
    std::cout << count << '\n';
    return 0;
}
