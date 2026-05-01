#include <iostream>

int main() {
    long long n = 100;
    
    long long sum_of_squares = n * (n + 1) * (2 * n + 1) / 6;
    long long sum = n * (n + 1) / 2;
    long long square_of_sum = sum * sum;
    
    long long difference = square_of_sum - sum_of_squares;
    
    std::cout << difference << std::endl;
              
    return 0;
}
