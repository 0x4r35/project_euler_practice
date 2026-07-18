# Project Euler Problem 61: Cyclical Figurate Numbers

## Problem Statement

Find the only ordered set of six cyclic four-digit numbers where each number is a different figurate type:
triangle, square, pentagonal, hexagonal, heptagonal, and octagonal.

**Goal**: Return the sum of those six numbers.

## Algorithmic Approach

1. Generate every four-digit figurate number for polygonal types 3 through 8.
2. Store the first two digits and last two digits for each number.
3. Use backtracking:
   - Start with an octagonal number to avoid checking the same cycle in every rotation.
   - Pick one unused figurate type at each step.
   - Keep only candidates whose first two digits match the previous number's last two digits.
   - At depth 6, verify that the final number links back to the first number.

Numbers ending in `00` through `09` are skipped because they cannot link to the first two digits of a four-digit number.

## Complexity Analysis

- **Time Complexity**: Small exponential search over the six figurate types, heavily limited by two-digit prefix matching.
- **Space Complexity**: `O(N)` for the generated four-digit figurate numbers.

## Answer

28684
