# Problem 004 — Largest Palindrome Product

[Problem Link](https://projecteuler.net/problem=4)

## Problem Statement
Find the largest palindrome made from the product of two 3-digit numbers.

## Approach

### C — Brute Force with Early Exit
- Iterate `i` from 999 down, `j` from `i` down (avoid duplicates)
- Break inner loop when `product <= current_best` (products only shrink)
- Check palindrome by digit reversal

### C++ — Divisibility by 11 Optimization
Key mathematical insight: Any 6-digit palindrome `abccba` can be written as:
```
100001a + 10010b + 1100c = 11 × (9091a + 910b + 100c)
```
So **every 6-digit palindrome is divisible by 11**.

This means `i × j ≡ 0 (mod 11)`, so at least one of `i` or `j` must be divisible by 11. We check:
- If `i % 11 == 0` → j can be anything
- If `i % 11 != 0` → j must be a multiple of 11, so step by 11

This cuts the inner loop iterations by ~11× in most cases.

## Complexity
| Solution | Time | Space |
|----------|------|-------|
| C (brute force + early exit) | O(n²) worst case, much less in practice | O(1) |
| C++ (div by 11) | ~O(n²/11) effectively | O(1) |

## Answer
**906609** (= 913 × 993)

## Key Learnings
- Palindromic numbers have special divisibility properties
- `abccba = 11 × (9091a + 910b + 100c)` — always divisible by 11!
- Searching from largest down + early exit makes brute force practical
- String reversal is a clean way to check palindromes but digit reversal avoids allocations
