# Project Euler Problem 38: Pandigital Multiples

## Problem Statement
Take some fixed integer and multiply it by 1, 2, 3, ... and concatenate the results. What is the **largest** 1 to 9 pandigital 9-digit number that can be formed as such a concatenated product, with $n > 1$?

## Approach
1. **Iterate** over candidate integers from 1 to 9999.
2. For each candidate, **concatenate** the products with $1, 2, 3, \ldots$ until the concatenated string has at least 9 digits.
3. If the result is exactly 9 digits and contains each of 1–9 exactly once (pandigital), **record** it.
4. Track and return the **maximum** value found.

## Key Observations
- We're told that 9 × (1, 2, 3, 4, 5) = 918273645 is an example, so the answer must be ≥ 918273645.
- Since $n > 1$, the candidate integer is at most 4 digits (a 5-digit number × 1 already gives 5 digits, and × 2 gives at least 5 more = 10+ digits total).
- For 4-digit candidates starting with 9, we get: 9xxx concatenated with 18xxx+, giving 9 digits. So we focus on 4-digit numbers starting with 9.
- The answer comes from $i = 9327$: $9327 \times 1 = 9327$, $9327 \times 2 = 18654$, concatenated = 932718654.

## Complexity
- **Time**: $O(9999 \cdot d)$ where $d$ is the max concatenation length ≈ constant.
- **Space**: $O(1)$ (just string buffers).

## Answer
$$\boxed{932718654}$$
