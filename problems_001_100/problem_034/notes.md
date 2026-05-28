# Project Euler Problem 34: Digit Factorials

## Problem Analysis
We need to find all numbers $n \ge 10$ such that the sum of the factorials of their digits equals $n$. 
First, we must establish an upper bound to know when to stop searching.

Let's look at the maximum possible sum of factorials for numbers of various lengths, knowing that $9! = 362880$:
- A 7-digit number can have a maximum digit factorial sum of $7 \times 9! = 2540160$. 
- An 8-digit number can have a maximum digit factorial sum of $8 \times 9! = 2903040$.

Since $2903040$ is only a 7-digit number, no 8-digit number (which must be at least $10000000$) can possibly equal the sum of the factorials of its digits. Therefore, our absolute upper bound for the search is $2540160$.

## Finding the Numbers
By iterating from $10$ to $2540160$ and precomputing the factorials from $0!$ to $9!$ for $O(1)$ lookups, we discover exactly two numbers that satisfy the condition:
1. $145 = 1! + 4! + 5! = 1 + 24 + 120$
2. $40585 = 4! + 0! + 5! + 8! + 5! = 24 + 1 + 120 + 40320 + 120$

## Final Calculation
Summing these numbers together:
$$145 + 40585 = 40730$$

