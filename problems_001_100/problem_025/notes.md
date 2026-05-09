# Problem 25: 1000-digit Fibonacci Number

## Approach
Since standard integer types in C/C++ (like `unsigned long long`) can only hold numbers up to ~20 digits, we cannot compute the 1000-digit Fibonacci numbers directly using built-in primitives. Instead, we can simulate big integer addition using arrays or vectors. Each element stores a single digit, and we perform primary school addition with a carry.

We maintain the two most recent Fibonacci numbers `f1` and `f2`. We continuously compute the next number by adding them digit by digit, updating our arrays until the number of digits reaches 1000.

## Complexity Analysis
- **Time Complexity:** $\mathcal{O}(N \times D)$ where $N$ is the target index of the Fibonacci sequence and $D$ is the maximum number of digits (1000). Since $N \approx 4782$ for 1000 digits, the number of operations is relatively small (around $5 \times 10^6$), making it extremely fast.
- **Space Complexity:** $\mathcal{O}(D)$, where $D = 1000$ digits. We only store three arrays (or vectors) of maximum 1000 size.
