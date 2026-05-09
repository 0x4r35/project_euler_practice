# Problem 005 — Smallest Multiple

[Problem Link](https://projecteuler.net/problem=5)

## Problem Statement
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

## Approach

### Both C and C++ — Iterative LCM
The smallest number divisible by all of 1..20 is their **Least Common Multiple**:
```
LCM(1, 2, ..., 20) = LCM(LCM(LCM(1, 2), 3), ..., 20)
```
Using the identity: `LCM(a, b) = a × b / GCD(a, b)`

### Prime Factorization Verification
We can also compute this by hand using prime powers:
- For each prime p ≤ 20, include the highest power p^k where p^k ≤ 20

| Prime | Highest power ≤ 20 |
|-------|-------------------|
| 2 | 2⁴ = 16 |
| 3 | 3² = 9 |
| 5 | 5¹ = 5 |
| 7 | 7¹ = 7 |
| 11 | 11¹ = 11 |
| 13 | 13¹ = 13 |
| 17 | 17¹ = 17 |
| 19 | 19¹ = 19 |

Result: 16 × 9 × 5 × 7 × 11 × 13 × 17 × 19 = **232792560**

## Complexity
| Solution | Time | Space |
|----------|------|-------|
| Iterative LCM | O(n log m) where m is max value | O(1) |

## Answer
**232792560**

## Key Learnings
- `LCM(a, b) = a / GCD(a, b) * b` — divide first to prevent overflow!
- The Euclidean algorithm for GCD is O(log(min(a,b))) — very fast
- C++17 provides `std::gcd` in `<numeric>` — no need to implement manually
- LCM of 1..n is the product of highest prime powers ≤ n (fundamental theorem of arithmetic)
