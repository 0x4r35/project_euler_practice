# Problem 003 — Largest Prime Factor

[Problem Link](https://projecteuler.net/problem=3)

## Problem Statement
What is the largest prime factor of the number 600851475143?

## Approach

### Trial Division (Both C and C++)
1. Divide out all factors of 2 first
2. Then try odd divisors from 3 upward, only up to √n
3. Each time a factor is found, divide it out completely
4. After the loop, if n > 1, the remaining n is the largest prime factor

**Why this works:** Any composite number n must have a prime factor ≤ √n. So if after dividing out all factors up to √n we still have n > 1, that remaining n must be prime.

**Why we divide out completely:** By removing each factor entirely, we reduce n quickly, making the √n bound shrink and the search faster.

## Complexity
| Solution | Time | Space |
|----------|------|-------|
| Trial division | O(√n) worst case | O(1) |

For n = 600,851,475,143 → √n ≈ 775,146, so at most ~387,573 iterations.

## Answer
**6857**

## Key Learnings
- Trial division is efficient enough for numbers up to ~10^12
- A number can have at most ONE prime factor greater than its square root
- Dividing out small factors progressively reduces the search space
- `long long` is essential — 600 billion overflows `int` (max ~2.1 billion)
