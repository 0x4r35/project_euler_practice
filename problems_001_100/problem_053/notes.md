# Project Euler Problem 53: Combinatoric Selections

## Problem Statement

There are exactly ten ways of selecting three from five, 12345: 123, 124, 125, 134, 135, 145, 234, 235, 245, and 345. In combinatorics, we use the notation $\binom{5}{3} = 10$.

It is not until $n = 23$ that a value exceeds one-million: $\binom{23}{10} = 1144066$.

**Goal**: How many, not necessarily distinct, values of $\binom{n}{r}$ for $1 \le n \le 100$, are greater than one-million?

## Algorithmic Approach

1. **Pascal's Triangle**: Build the binomial coefficient table using the recurrence $\binom{n}{r} = \binom{n-1}{r-1} + \binom{n-1}{r}$, with base case $\binom{n}{0} = 1$.
2. **Capping Values**: Since we only need to know whether $\binom{n}{r} > 1{,}000{,}000$, we cap any value exceeding 1,000,000 at a sentinel (1,000,001). This prevents overflow while preserving the correctness of the recurrence — if either summand is already capped, the result will also exceed the threshold.
3. **Counting**: Simply count how many entries exceed 1,000,000 during construction.

## Complexity Analysis

- **Time Complexity**: $\mathcal{O}(n^2)$ for filling Pascal's triangle with $n = 100$, so roughly 5,050 operations.
- **Space Complexity**: $\mathcal{O}(n^2)$ for the 2D table. Could be reduced to $\mathcal{O}(n)$ by computing one row at a time, but the small size makes this unnecessary.

## Answer

4075
