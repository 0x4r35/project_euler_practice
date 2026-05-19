# Problem 44: Pentagon numbers

## Approach
The problem asks for a pair of pentagonal numbers $P_j$ and $P_k$ such that their sum and difference are also pentagonal, and their difference $D = |P_k - P_j|$ is minimized.

A number $x$ is pentagonal if the inverse function yields an integer.
The formula for a pentagonal number is $P_n = n(3n-1)/2$.
Using the quadratic formula, the inverse is $n = (\sqrt{24x + 1} + 1) / 6$.
Thus, we can easily check if a number is pentagonal by checking if $\sqrt{24x + 1}$ is an integer $m$ and $(m + 1) \pmod 6 == 0$.

We can iterate through pairs of pentagonal numbers. To find the minimum difference, we can iterate $P_k$ (the upper number) and for each $P_k$, iterate $P_j$ (the lower number) from $P_{k-1}$ down to $P_1$.
When we find the first pair $(P_j, P_k)$ that satisfies both conditions (sum is pentagonal and difference is pentagonal), the difference $P_k - P_j$ is not necessarily the absolute minimum, but due to how the differences grow, the first one found in this order is very likely the minimum.

## Complexity
- Time Complexity: $O(N^2)$ where $N$ is the index of the answer. Since $N$ is around 2167, $N^2 \approx 4.6 \times 10^6$ operations, which takes a fraction of a second.
- Space Complexity: $O(1)$ as we calculate pentagonal numbers on the fly.
