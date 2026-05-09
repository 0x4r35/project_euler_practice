#include <iostream>

int main() {
    // We are solving 40 Choose 20
    const int n = 40;
    const int k = 20;
    
    // Use unsigned long long because the answer is massive
    unsigned long long paths = 1;

    // Calculate n! / (k! * (n-k)!) efficiently
    for (int i = 1; i <= k; i++) {
        paths = paths * (n - i + 1) / i;
    }

    std::cout << "The number of paths through a 20x20 grid is: " << paths << std::endl;

    return 0;
}


// fun fact:  C++ solution avoids the grid entirely and just calculates $\binom{40}{20}$. It is blindingly fast and takes almost zero memory.