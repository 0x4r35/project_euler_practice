# Project Euler Problem 40: Champernowne's Constant

## Problem Statement
An irrational decimal fraction is created by concatenating the positive integers:
$$0.123456789101112131415161718192021...$$

It can be seen that the $12^{\text{th}}$ digit of the fractional part is $1$.

If $d_n$ represents the $n^{\text{th}}$ digit of the fractional part, find the value of the following expression:
$$d_1 \times d_{10} \times d_{100} \times d_{1000} \times d_{10000} \times d_{100000} \times d_{1000000}$$

## Approach
1. **Streaming Digit Concatenation Counter**:
   Instead of generating a massive string in memory (which requires allocating $10^6$ characters and managing string buffers), we can keep track of the current cumulative digit index `curr_index` as we iterate through consecutive integers $1, 2, 3, \ldots$.
2. **Dynamic Range Checking**:
   For each integer `num`:
   - Compute its length `num_len`.
   - Check if the target index falls within the range $[ \text{curr\_index} + 1, \text{curr\_index} + \text{num\_len} ]$.
   - If it does, extract the corresponding digit at relative offset `target - curr_index` from the left of `num` (e.g., `num_len - (target - curr_index)`-th digit from the right).
   - Multiply the extracted digit into our running product and advance to the next target index.
   - Increment `curr_index` by `num_len`.
3. **Loop Termination**:
   The search terminates immediately once all 7 target indices are satisfied.

## Key Observations
- This approach requires $O(1)$ auxiliary space since no strings are stored.
- Extremely efficient time complexity because the integers up to the $1,000,000^{\text{th}}$ digit are only around $185,185$, leading to less than $200,000$ iterations.

## Complexity
- **Time**: $O(K \log_{10} K)$ where $K$ is the largest target index ($10^6$) — in practice, runs in under 1 millisecond.
- **Space**: $O(1)$ auxiliary space.

## Answer
$$\boxed{210}$$
