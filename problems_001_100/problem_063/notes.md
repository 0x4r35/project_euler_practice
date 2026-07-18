# Project Euler Problem 63: Powerful Digit Counts

## Problem Statement

Count how many positive integers are also an `n`-digit `n`th power.

## Algorithmic Approach

1. Only bases 1 through 9 need to be checked. Any `10^n` or larger base produces at least `n + 1` digits.
2. For each base, multiply a small decimal big integer by the base to generate consecutive powers.
3. Count the power whenever its decimal digit length equals the exponent.
4. Stop checking a base once the digit length is smaller than the exponent. Since every base is less than 10, the digit length will then continue falling behind.

The largest relevant power is small, but storing digits directly avoids overflow and floating-point rounding concerns.

## Complexity Analysis

- **Time Complexity**: `O(B * E * D)` where `B = 9`, `E` is the highest exponent checked, and `D` is the number of decimal digits.
- **Space Complexity**: `O(D)` for the current power.

## Answer

49
