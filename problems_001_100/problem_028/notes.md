# Problem 28: Number Spiral Diagonals

## Approach
Instead of generating the 1001x1001 grid, we can observe a mathematical pattern in the diagonals.
For an $n \times n$ spiral (where $n$ is an odd number $\ge 3$), the four corners are:
- Top right: $n^2$
- Top left: $n^2 - (n - 1)$
- Bottom left: $n^2 - 2(n - 1)$
- Bottom right: $n^2 - 3(n - 1)$

Summing these four corners gives $4n^2 - 6(n - 1) = 4n^2 - 6n + 6$.
We can accumulate this sum for all odd numbers $n$ from 3 to 1001, starting with an initial sum of 1 for the center.

## Complexity Analysis
- **Time Complexity:** $O(N)$ where $N$ is the side length of the spiral (specifically $O(N/2)$ iterations).
- **Space Complexity:** $O(1)$ since we only use a few variables for the sum.

## Learnings
Deriving the mathematical formula for the corner values converts a simulation problem into a simple arithmetic progression calculation, vastly improving performance.

