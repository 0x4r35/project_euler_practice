# Project Euler Problem 55: Lychrel Numbers

## Problem Statement

If we take 47, reverse and add, 47 + 74 = 121, which is palindromic. Not all numbers produce palindromes so quickly. For example:

- 349 + 943 = 1292
- 1292 + 2921 = 4213
- 4213 + 3124 = 7337 (palindrome in 3 iterations)

A number that never forms a palindrome through the reverse-and-add process is called a Lychrel number. For this problem, we assume a number is Lychrel if it hasn't produced a palindrome within 50 iterations.

**Goal**: How many Lychrel numbers are there below ten-thousand?

## Algorithmic Approach

1. **Big Number Arithmetic**: Since reverse-and-add can quickly produce numbers far exceeding 64-bit integer range (after 50 iterations starting from ~10000), we must use arbitrary-precision arithmetic. The C solution stores digits in an array; the C++ solution uses string-based addition.
2. **Reverse and Add Loop**: For each number from 1 to 9999:
   - Convert to big number representation.
   - Repeat up to 50 times: add the number to its digit-reverse, then check if the result is a palindrome.
   - If a palindrome is found within 50 iterations, the number is not Lychrel.
3. **Palindrome Check**: Compare digits from both ends toward the center.
4. **Count**: Tally numbers for which no palindrome was found after 50 iterations.

## Complexity Analysis

- **Time Complexity**: $\mathcal{O}(N \times I \times D)$ where $N = 9999$ numbers, $I = 50$ max iterations, and $D$ is the maximum digit count (roughly 100+ digits after many additions). Each addition and palindrome check is $\mathcal{O}(D)$.
- **Space Complexity**: $\mathcal{O}(D)$ for the big number storage, where $D$ grows up to about 100–200 digits.

## Answer

249
