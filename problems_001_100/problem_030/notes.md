# Problem 30: Digit Fifth Powers

## Approach
We are looking for numbers that can be written as the sum of fifth powers of their digits.
First, we must establish an upper bound. The maximum value for a digit's fifth power is $9^5 = 59049$. 
If a number has 6 digits, the maximum possible sum of its digits' fifth powers is $6 \times 59049 = 354294$. 
If it has 7 digits, the maximum is $7 \times 59049 = 413343$, which is a 6-digit number. Hence, no 7-digit number or larger can satisfy the condition. The upper bound is therefore around 355,000.
We can simply iterate from 10 to 355000, checking if the sum of the fifth powers of the digits equals the number itself. Precomputing the fifth powers of digits 0-9 saves computation time.

## Complexity Analysis
- **Time Complexity:** $O(N \log_{10} N)$ where $N$ is the upper bound (approx. 355,000), as we process the digits of each number.
- **Space Complexity:** $O(1)$ since we only store a precomputed array of 10 integers.

## Learnings
Finding the logical upper bound is the key to solving this problem efficiently by limiting the search space. Precomputing repeated values (like powers of digits) is a standard optimization.
