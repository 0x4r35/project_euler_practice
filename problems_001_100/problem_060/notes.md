# Project Euler Problem 60: Prime Pair Sets

## Problem Statement

Find a set of five primes where any two primes concatenate in either order to produce another prime.

**Goal**: Find the lowest possible sum for such a set.

## Algorithmic Approach

1. Generate all primes below 10000. The minimal known set is contained in this range, and the search still verifies the concatenation property exactly.
2. Exclude 2 and 5 because any concatenation ending in 2 or 5 would be composite.
3. Use a recursive clique search:
   - Add primes in increasing order.
   - Before adding a prime, verify it is compatible with every prime already chosen.
   - Cache pair compatibility so every pair is tested at most once.
4. Prune any branch whose smallest possible remaining sum cannot beat the current best sum.

Concatenation primality is checked by trial division using the generated primes.

## Complexity Analysis

- **Time Complexity**: Exponential in the clique size search, heavily reduced by compatibility caching and sum pruning.
- **Space Complexity**: `O(P^2)` for the compatibility cache, where `P` is the number of candidate primes.

## Answer

26033
