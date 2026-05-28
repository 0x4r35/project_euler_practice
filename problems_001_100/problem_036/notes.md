# Project Euler Problem 36: Double-base Palindromes

## Problem Statement
Find the sum of all numbers less than one million which are palindromic in **both base 10 and base 2**. Note: the palindromic number, in either base, must not include leading zeros.

## Approach
1. **Iterate** through all numbers from 1 to 999,999.
2. **Check base-10 palindrome**: Convert to string and verify symmetry.
3. **Check base-2 palindrome**: Convert to binary string and verify symmetry.
4. **Sum** all numbers satisfying both conditions.

## Key Observations
- We can skip even numbers since their binary representation ends in 0, meaning it would have a leading zero when reversed — violating the palindrome condition. This halves our search space.
- The brute-force approach is efficient enough since we only need to check < 10^6 numbers, and each check is O(d) where d is the number of digits.

## Complexity
- **Time**: $O(n \cdot d)$ where $n = 10^6$ and $d \leq 20$ (binary digits).
- **Space**: $O(d)$ for string buffers.

## Answer
$$\boxed{872187}$$
