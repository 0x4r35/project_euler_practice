#include <stdio.h>

#define LIMIT 1000000

// We use an array to "cache" (remember) lengths we've already calculated
int cache[LIMIT] = {0};

int main() {
    int max_length = 0;
    int best_starting_number = 0;

    // Base case: The length of the sequence for 1 is 1.
    cache[1] = 1;

    for (int i = 1; i < LIMIT; i++) {
        long long n = i; // Must use long long to prevent overflow!
        int count = 0;

        // Keep calculating until we hit 1, OR until we hit a number we already solved
        while (n >= LIMIT || cache[n] == 0) {
            if (n % 2 == 0) {
                n = n / 2;
            } else {
                n = 3 * n + 1;
            }
            count++;
        }

        // The total length is the steps we took + the known length of the number we landed on
        cache[i] = count + cache[n];

        // Check if this is the longest chain we've seen so far
        if (cache[i] > max_length) {
            max_length = cache[i];
            best_starting_number = i;
        }
    }

    printf("Starting number with the longest chain: %d\n", best_starting_number);
    printf("Length of chain: %d\n", max_length);

    return 0;
}