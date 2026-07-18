# Project Euler Problem 62: Cubic Permutations

## Problem Statement

Find the smallest cube for which exactly five permutations of its digits are also cubes.

## Algorithmic Approach

1. Iterate through cubes in increasing base order.
2. Convert each cube into a digit signature by sorting its digits.
3. Group cubes with the same signature.
4. Process one digit length at a time. When the cube length increases, all groups for the previous length are complete.
5. Return the smallest cube from any completed group that contains exactly five cubes.

Grouping by digit length is important because adding a digit changes the permutation space, so no future cube can join an older group.

## Complexity Analysis

- **Time Complexity**: `O(N * D log D)` in C++ for sorting `D` digits per cube; the C version uses digit counts, so it is `O(N * D)`.
- **Space Complexity**: `O(G * D)` for the groups in a single digit length.

## Answer

127035954683
