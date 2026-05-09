#include <stdio.h>
#include <math.h>

// Function to calculate the number of divisors
int count_divisors(long long n) {
    int count = 0;
    long long limit = (long long)sqrt(n);
    
    for (long long i = 1; i <= limit; i++) {
        if (n % i == 0) {
            count += 2; // Add both 'i' and 'n/i'
        }
    }
    
    // If the number is a perfect square, we accidentally counted the square root twice.
    if (limit * limit == n) {
        count--;
    }
    
    return count;
}

int main() {
    long long n = 1;
    long long triangle_num = 1;

    // Keep generating triangle numbers until we find one with > 500 divisors
    while (count_divisors(triangle_num) <= 500) {
        n++;
        triangle_num += n; // Add the next natural number to get the next triangle number
    }

    printf("The first triangle number with over 500 divisors is: %lld\n", triangle_num);
    return 0;
}