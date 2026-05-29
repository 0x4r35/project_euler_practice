# Project Euler Problem 50: Consecutive Prime Sum

## Problem Statement

The prime 41, can be written as the sum of six consecutive primes:
41 = 2 + 3 + 5 + 7 + 11 + 13

This is the longest sum of consecutive primes that adds to a prime below one-hundred.
The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

**Goal**: Which prime, below one-million, can be written as the sum of the most consecutive primes?

## Algorithmic Approach

1. **Generate Primes**: Use the Sieve of Eratosthenes to identify all prime numbers below 1,000,000. Store these primes in an ordered array.
2. **Cumulative Sums**: Create an array of cumulative sums of the primes. `cumulative_sum[i]` will store the sum of all primes from index `0` up to `i-1`. This allows calculating the sum of any contiguous sequence of primes in $\mathcal{O}(1)$ time: `sum(i to j) = cumulative_sum[j] - cumulative_sum[i]`.
3. **Sliding Window Search**: 
   - Iterate through possible starting indices `i` and ending indices `j`.
   - To optimize, the inner loop for `j` should start at `i + current_max_length + 1`, because we are only interested in finding a *longer* sequence than we already have.
   - If the sum exceeds 1,000,000, break the inner loop early (as adding more primes will only increase the sum).
   - If the sum is a prime number (checked in $\mathcal{O}(1)$ using the boolean array from our Sieve), update the `max_length` and `best_prime`.

## Complexity Analysis

- **Time Complexity**: 
  - Sieve: $\mathcal{O}(N \log \log N)$ where $N = 1,000,000$.
  - Search: In the worst-case, $\mathcal{O}(P^2)$ where $P$ is the number of primes below $N$ (around 78,498). However, breaking early when the sum exceeds 1,000,000 drastically reduces the actual iterations. The longest sequence sum $\le 1,000,000$ only involves around 546 primes, meaning the inner loop terminates very quickly. Overall search is roughly $\mathcal{O}(P 	imes K)$ where $K  pprox 500$.
- **Space Complexity**: $\mathcal{O}(N)$ for the boolean sieve array, plus $\mathcal{O}(P)$ for the primes array and cumulative sums array. Easily fits in standard memory limits.