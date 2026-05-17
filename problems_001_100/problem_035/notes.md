# Project Euler Problem 35: Circular Primes

## Problem Statement
The number 197 is called a **circular prime** because all rotations of the digits: 197, 971, and 719, are themselves prime. How many circular primes are there below one million?

## Approach
1. **Sieve of Eratosthenes**: Generate all primes below 1,000,000 using a boolean sieve for $O(1)$ primality lookups.
2. **Digit Rotation**: For each prime, generate all cyclic rotations by repeatedly moving the leading digit to the end.
3. **Validation**: A number is a circular prime only if every single rotation is also prime.

## Key Observations
- Single-digit primes (2, 3, 5, 7) are trivially circular primes.
- For multi-digit circular primes, no digit can be even or 5 (except the single-digit cases), because a rotation placing that digit at the end would make the number divisible by 2 or 5.
- This observation could be used as an optimization filter, though the brute-force sieve approach is fast enough for $n < 10^6$.

## Complexity
- **Time**: $O(n \log \log n)$ for the sieve + $O(n \cdot d)$ for checking rotations where $d$ is the number of digits (at most 6).
- **Space**: $O(n)$ for the sieve array.

## Answer
$$\boxed{55}$$
