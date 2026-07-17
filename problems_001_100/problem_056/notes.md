# Project Euler Problem 56: Powerful Digit Sum

## Problem Statement

For natural numbers `a, b < 100`, consider the decimal digit sum of `a^b`.

**Goal**: Find the maximum digital sum.

## Algorithmic Approach

1. Store large powers as decimal digits in reverse order.
2. For each base `a` from 1 to 99, start with 1 and multiply by `a` repeatedly to get `a^1` through `a^99`.
3. After every multiplication, sum the stored digits.
4. Track the largest digit sum found.

This avoids floating point arithmetic and keeps every digit exact.

## Complexity Analysis

- **Time Complexity**: `O(100 * 100 * D)` where `D` is the number of decimal digits in the largest power.
- **Space Complexity**: `O(D)` for the current big integer.

## Answer

972
