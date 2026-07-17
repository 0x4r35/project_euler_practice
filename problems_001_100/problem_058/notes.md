# Project Euler Problem 58: Spiral Primes

## Problem Statement

Starting with 1 and spiraling anticlockwise, the square side lengths `3, 5, 7, ...` add four new diagonal corner values each.

**Goal**: Find the side length where the ratio of primes along both diagonals first falls below 10%.

## Algorithmic Approach

For an odd side length `s`, the top-right corner is `s^2`, and the four corners are:

- `s^2`
- `s^2 - (s - 1)`
- `s^2 - 2(s - 1)`
- `s^2 - 3(s - 1)`

The program grows the spiral one ring at a time, tests those four numbers for primality, and keeps the total diagonal count. The first side length where `prime_count / diagonal_count < 0.10` is printed.

## Complexity Analysis

- **Time Complexity**: `O(R * sqrt(N))` with trial division for the corner values.
- **Space Complexity**: `O(1)`.

## Answer

26241
