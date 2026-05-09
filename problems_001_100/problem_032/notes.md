# Project Euler 32 - Pandigital Products

## Problem Analysis
An $n$-digit number is pandigital if it makes use of all the digits 1 to $n$ exactly once. We need to find the sum of all unique products `c` where `a * b = c` and the full identity contains the digits 1 through 9 exactly once.

## Mathematical Bounds
Let the number of digits in $a$, $b$, and $c$ be $x$, $y$, and $z$ respectively.
We know that $x + y + z = 9$.
The product of an $x$-digit number and a $y$-digit number has either $x+y$ or $x+y-1$ digits.

1. **Case 1 ($z = x + y$):** $x + y + x + y = 9 \implies 2(x + y) = 9$. This is impossible since 9 is odd.
2. **Case 2 ($z = x + y - 1$):** $x + y + x + y - 1 = 9 \implies 2(x + y) = 10 \implies x + y = 5$.
   
Since $x + y = 5$, we know $z = 9 - 5 = 4$. Thus, the product must be exactly 4 digits.

The possible length pairs for the multiplicand and multiplier $(x, y)$ are:
* **$1$-digit $\times$ $4$-digit = $4$-digit** (e.g., $a \in [2, 9]$, $b \in [1234, 9876]$)
* **$2$-digit $\times$ $3$-digit = $4$-digit** (e.g., $a \in [12, 98]$, $b \in [123, 987]$)

*(Note: $a$ cannot be 1 because $1 \times b = b$, which would immediately duplicate the digits of $b$).*

## Algorithm
1. Iterate through possible values of $a$ (from 2 to 99).
2. Based on the number of digits in $a$, determine the starting and ending bounds for $b$ to ensure the product stays within 4 digits (under 10000).
3. Calculate $c = a \times b$. 
4. Check if the concatenation of $a, b, c$ is 1-9 pandigital. This is efficiently done using bitwise operations: a valid number will set exactly bits 1 through 9, resulting in a bitmask of `1111111110` in binary (`1022` in decimal).
5. Track valid products `c` using a boolean array `seen[10000]` to ensure we don't count duplicates, adhering to the problem hint.
6. Sum all the unique valid products.