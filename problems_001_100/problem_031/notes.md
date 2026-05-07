# Problem 31: Coin Sums

## Approach
The problem asks for the number of ways to make £2 (200p) using standard British coins.
This is a classic dynamic programming problem (Unbounded Knapsack / Coin Change).
We define an array `ways` where `ways[j]` represents the number of ways to make amount `j`. We initialize `ways[0] = 1` (one way to make 0p, using no coins).
We iterate through each coin value, and for each coin, we update the `ways` array from the coin's value up to 200p. The relation is `ways[j] += ways[j - coin]`.

## Complexity Analysis
- **Time Complexity:** $O(N \times M)$ where $N$ is the number of coin types (8) and $M$ is the target amount (200). Very fast.
- **Space Complexity:** $O(M)$ to store the `ways` array up to the target amount.

## Learnings
Dynamic programming offers an elegant and optimally efficient approach to combinatorial counting problems compared to recursive backtracking, which can suffer from overlapping subproblems and large execution times.
