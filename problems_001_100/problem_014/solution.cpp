#include <iostream>
#include <vector>

int main() {
    const int LIMIT = 1000000;
    
    // Initialize a vector of size LIMIT with 0s to store our cached sequence lengths
    std::vector<int> cache(LIMIT, 0);
    cache[1] = 1; 

    int max_length = 0;
    int best_starting_number = 0;

    for (int i = 1; i < LIMIT; i++) {
        long long n = i; // Prevent integer overflow during spikes
        int count = 0;

        // Calculate sequence. If 'n' drops below LIMIT and we already know its cache value, stop!
        while (n >= LIMIT || cache[n] == 0) {
            if (n % 2 == 0) {
                n /= 2;
            } else {
                n = 3 * n + 1;
            }
            count++;
        }

        cache[i] = count + cache[n];

        if (cache[i] > max_length) {
            max_length = cache[i];
            best_starting_number = i;
        }
    }

    std::cout << "Starting number with the longest chain: " << best_starting_number << std::endl;
    std::cout << "Length of chain: " << max_length << std::endl;

    return 0;
}