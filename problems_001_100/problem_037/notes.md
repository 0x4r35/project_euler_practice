# Project Euler Problem 37: Truncatable Primes

## Problem Statement
Find the sum of the only **eleven primes** that are both truncatable from left to right and right to left. Single-digit primes (2, 3, 5, 7) are not considered truncatable.

## Approach
1. **Sieve of Eratosthenes**: Generate all primes below 1,000,000.
2. **Right Truncation**: Repeatedly remove the last digit and check if the result is prime (e.g., 3797 → 379 → 37 → 3).
3. **Left Truncation**: Repeatedly remove the first digit and check if the result is prime (e.g., 3797 → 797 → 97 → 7).
4. **Collect**: Find all primes > 9 satisfying both conditions. It is known there are exactly 11 such primes.

## The 11 Truncatable Primes
23, 37, 53, 73, 313, 317, 373, 797, 3137, 3797, 739397

## Complexity
- **Time**: $O(n \log \log n)$ for sieve + $O(n \cdot d)$ for checking truncations.
- **Space**: $O(n)$ for the sieve.

## Answer
$$\boxed{748317}$$
