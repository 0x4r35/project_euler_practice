# Problem 006 — Sum square difference

[Problem Link](https://projecteuler.net/problem=6)

## Problem Statement
Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

## Approach

### C / C++ — Mathematical Formula (O(1))
Using the formulas for the sum of the first `n` natural numbers and the sum of their squares:
- Sum of the first `n` natural numbers: `n × (n + 1) / 2`
- Sum of the squares of the first `n` natural numbers: `n × (n + 1) × (2n + 1) / 6`

By computing both and taking the difference, we achieve an `O(1)` time complexity solution instead of an `O(n)` looping approach.

## Complexity
| Solution | Time | Space |
|----------|------|-------|
| C / C++ (math) | O(1) | O(1) |

## Answer
**25164150**

## Key Learnings
- Mathematical formulas reduce iteration overhead.
