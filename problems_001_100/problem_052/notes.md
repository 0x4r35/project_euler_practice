# Project Euler Problem 52: Permuted Multiples

## Problem Statement

It can be verified that 125874 and its double, 251748, contain exactly the same digits, but in a different order.

**Goal**: Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.

## Algorithmic Approach

1. **Digit Signature**: For any integer, compute a "signature" by counting occurrences of each digit (0–9). Two numbers have the same digits if and only if their signatures match.
2. **Brute Force Search**: Starting from x = 1, compute 2x through 6x and check whether all have the same digit signature as x.
3. **Early Exit**: As soon as any multiple fails the check, skip to the next x.

The answer is 142857, which is the cyclic number associated with the fraction 1/7. Its multiples 2×142857 = 285714, 3×142857 = 428571, etc., are all cyclic permutations of the same digits.

## Complexity Analysis

- **Time Complexity**: $\mathcal{O}(x \times d)$ where $d$ is the number of digits in the answer. The digit comparison is $\mathcal{O}(d)$ per multiple. The search terminates quickly at x = 142857.
- **Space Complexity**: $\mathcal{O}(1)$ — only fixed-size digit count arrays are needed.

## Answer

142857
