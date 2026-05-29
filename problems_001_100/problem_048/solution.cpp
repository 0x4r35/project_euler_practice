#include <iostream>
#include <iomanip>

int main() {
    const unsigned long long modulo = 10000000000ULL;
    unsigned long long sum = 0;

    for (int i = 1; i <= 1000; ++i) {
        unsigned long long term = 1;
        for (int j = 1; j <= i; ++j) {
            term = (term * i) % modulo;
        }
        sum = (sum + term) % modulo;
    }

    std::cout << std::setfill('0') << std::setw(10) << sum << '\n';
    
    return 0;
}