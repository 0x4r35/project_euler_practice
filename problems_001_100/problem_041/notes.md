# Project Euler Problem 41: Pandigital Prime

## Problem Statement
We shall say that an $n$-digit number is pandigital if it makes use of all the digits $1$ to $n$ exactly once. For example, $2143$ is a $4$-digit pandigital and is also prime.

What is the largest $n$-digit pandigital prime that exists?

## Approach
1. **Mathematical Reduction (Digit Sum Rule)**:
   An $n$-digit pandigital number contains all digits from $1$ to $n$ exactly once. Let's examine the sum of digits for various values of $n$:
   - $n = 9$: $1+2+3+4+5+6+7+8+9 = 45$ (divisible by 3)
   - $n = 8$: $1+2+3+4+5+6+7+8 = 36$ (divisible by 3)
   - $n = 7$: $1+2+3+4+5+6+7 = 28$ (not divisible by 3)
   - $n = 6$: $1+2+3+4+5+6 = 21$ (divisible by 3)
   - $n = 5$: $1+2+3+4+5 = 15$ (divisible by 3)
   - $n = 4$: $1+2+3+4 = 10$ (not divisible by 3)

   By the divisibility rules of arithmetic, any integer whose sum of digits is divisible by 3 is itself divisible by 3. Therefore, no 8-digit or 9-digit pandigital numbers can be prime! 
   Hence, the largest possible pandigital prime must be at most **7 digits** long.

2. **Reverse Lexicographical Permutations**:
   - Start with the largest 7-digit pandigital number, `7654321`.
   - Generate permutations in descending lexicographical order (using `std::prev_permutation` in C++ and a custom equivalent in C).
   - Check each permutation for primality using a fast trial-division primality test.
   - The first prime encountered is mathematically guaranteed to be the largest.

## Complexity
- **Time**: $O(P \cdot \sqrt{N})$ where $P$ is the number of permutations checked until a prime is found, and $N \leq 7,654,321$. The search finishes in less than 1 millisecond.
- **Space**: $O(1)$ auxiliary space.

## Answer
$$\boxed{7652413}$$
