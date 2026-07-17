# Project Euler Problem 57: Square Root Convergents

## Problem Statement

The continued fraction for `sqrt(2)` produces fractions such as:

- `3/2`
- `7/5`
- `17/12`
- `41/29`

**Goal**: In the first 1000 expansions, count how many fractions contain a numerator with more digits than the denominator.

## Algorithmic Approach

For each expansion `n/d`, the next expansion is:

- numerator: `n + 2d`
- denominator: `n + d`

The values grow beyond native integer types, so the code uses exact decimal big integers. For every expansion, compare the digit counts of numerator and denominator, then update the fraction using the recurrence.

## Complexity Analysis

- **Time Complexity**: `O(E * D)` where `E = 1000` expansions and `D` is the digit count.
- **Space Complexity**: `O(D)` for the current numerator and denominator.

## Answer

153
