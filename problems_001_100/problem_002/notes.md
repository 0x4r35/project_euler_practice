# Problem 002 — Even Fibonacci Numbers

[Problem Link](https://projecteuler.net/problem=2)

## Problem Statement
Find the sum of the even-valued terms in the Fibonacci sequence whose values do not exceed four million.

## Approach

### C — Standard Fibonacci + Even Check
Generate Fibonacci numbers, check if even with `% 2 == 0`, accumulate.

### C++ — Even Fibonacci Recurrence (Optimized)
Key insight: every 3rd Fibonacci number is even (pattern: O, O, **E**, O, O, **E**, ...).

We can derive a recurrence that generates **only** even Fibonacci numbers:
```
E(n) = 4 × E(n-1) + E(n-2)
```
Starting with E(1) = 2, E(2) = 8, this gives: 2, 8, 34, 144, 610, ...

**Proof:** If F(3k) is even, then F(3k+3) = F(3k+2) + F(3k+1) = ... = 4·F(3k) + F(3k-3)

## Complexity
| Solution | Time | Space |
|----------|------|-------|
| C (standard) | O(n) where n ≈ 33 Fibonacci terms | O(1) |
| C++ (even-only) | O(n/3) ≈ 11 iterations | O(1) |

## Answer
**4613732**

## Key Learnings
- Fibonacci numbers have a periodicity pattern for divisibility (Pisano period)
- Every 3rd Fibonacci number is even — this is provable from the O, O, E pattern
- Deriving sub-recurrences can eliminate unnecessary computation

