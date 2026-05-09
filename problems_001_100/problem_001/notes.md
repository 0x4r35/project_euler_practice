# Problem 001 — Multiples of 3 or 5

[Problem Link](https://projecteuler.net/problem=1)

## Problem Statement
Find the sum of all the multiples of 3 or 5 below 1000.

## Approach

### C — Brute Force
Simple iteration from 1 to 999, checking if each number is divisible by 3 or 5.

### C++ — Inclusion-Exclusion Principle (O(1))
Using the arithmetic series formula: `sum of multiples of n below L = n × k × (k+1) / 2` where `k = (L-1) / n`

By inclusion-exclusion:
```
Answer = sum_multiples(3) + sum_multiples(5) - sum_multiples(15)
```
We subtract multiples of 15 because those are counted twice (divisible by both 3 and 5).

## Complexity
| Solution | Time | Space |
|----------|------|-------|
| C (brute force) | O(n) | O(1) |
| C++ (math) | O(1) | O(1) |

## Answer
**233168**

## Key Learnings
- Inclusion-exclusion principle avoids double counting
- Arithmetic series formula: `S = n(n+1)/2` is incredibly useful
- Always look for a mathematical shortcut before brute forcing
