# Project Euler Problem 47: Distinct Primes Factors

## Problem Statement

The first two consecutive numbers to have two distinct prime factors are:
14 = 2 × 7
15 = 3 × 5

The first three consecutive numbers to have three distinct prime factors are:
644 = 2² × 7 × 23
645 = 3 × 5 × 43
646 = 2 × 17 × 19

**Goal**: Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?

## Algorithmic Approach

To efficiently solve this problem without repeatedly factoring each number from scratch, we use a variation of the **Sieve of Eratosthenes**. Instead of using the sieve to simply mark numbers as prime or composite, we use it to compute the number of distinct prime factors for each integer. In number theory, this count is often denoted by the prime omega function, `ω(n)`.

### The Modified Sieve Execution

1. **Memory Allocation**: We allocate an array (let's call it `omega`) up to a predefined limit (e.g., 1,000,000) and initialize all elements to 0. 
2. **Counting Factors**: 
   - We iterate through the array starting from `i = 2`.
   - If `omega[i]` is exactly 0, it means the number hasn't been visited by any smaller prime factor. Thus, `i` itself is a prime.
   - For every prime `i` found, we iterate through all of its multiples (`i, 2i, 3i, ...`) up to the maximum limit and increment the value at `omega[multiple]` by 1. By the end of this process, `omega[x]` holds the exact number of distinct prime factors for `x`.
3. **Finding the Target Streak**:
   - We loop through the populated `omega` array and keep track of consecutive successes.
   - If we find a number where `omega[i] == 4`, we increment our `streak` counter.
   - If the counter hits 4, we have found our answer. The first number in this 4-number sequence will be `i - 3`.
   - If we encounter a number where `omega[i]` is not 4, we immediately reset the streak counter to 0.

## Complexity Analysis

- **Time Complexity**: $\mathcal{O}(N \log \log N)$ where $N$ is our search limit. The inner loop executes $rac{N}{p}$ times for each prime $p$. The sum of the reciprocals of the primes up to $N$ grows asymptotically as $\log \log N$, making this approach extremely fast.
- **Space Complexity**: $\mathcal{O}(N)$. We require an array of size $N$ to store the prime factor counts. For a limit of 1,000,000 using standard 32-bit integers, this consumes about 4 MB of memory, which is trivial for modern systems.