# Project Euler Problem 51: Prime Digit Replacements

## Problem Statement

By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.

By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes among the ten generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993.

**Goal**: Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family.

## Algorithmic Approach

1. **Sieve of Eratosthenes**: Generate all primes below 1,000,000 using a boolean sieve array for $\mathcal{O}(1)$ primality checks.
2. **Iterate Primes**: For each prime, extract its digits and try all possible non-empty subsets of digit positions (using a bitmask over digit positions).
3. **Filter Valid Masks**: Only consider masks where all selected positions hold the same digit in the original prime. This ensures consistent replacement.
4. **Generate Family**: For each valid mask, replace the selected positions with digits 0–9 (skipping leading zeros), and count how many resulting numbers are prime.
5. **Check Family Size**: If the family has 8 or more primes, and the current prime is the smallest member, output it and terminate.

## Complexity Analysis

- **Time Complexity**: The sieve runs in $\mathcal{O}(N \log \log N)$. For each prime with $d$ digits, we check $2^d - 1$ masks. Since $d \le 6$ for primes below 1,000,000, at most 63 masks are checked per prime. Each mask involves at most 10 candidate evaluations. Total work is roughly $\mathcal{O}(\pi(N) \times 2^d \times 10)$ where $\pi(N) \approx 78498$ and $d \le 6$.
- **Space Complexity**: $\mathcal{O}(N)$ for the sieve array.

## Answer

121313
