# Project Euler Problem 42: Coded Triangle Numbers

## Problem Statement
The $n^{\text{th}}$ term of the sequence of triangle numbers is given by, $t_n = \frac{1}{2}n(n+1)$; so the first ten triangle numbers are:
$$1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...$$

By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is $19 + 11 + 25 = 55 = t_{10}$. If the word value is a triangle number then we shall call the word a triangle word.

Using `words.txt` (a 16K text file containing nearly two-thousand common English words), how many are triangle words?

## Approach
1. **Mathematical Triangle Test**:
   To determine if a word value $x$ is a triangle number, we solve the equation:
   $$x = \frac{1}{2}n(n+1) \implies n^2 + n - 2x = 0$$
   Using the quadratic formula, the positive root is:
   $$n = \frac{-1 + \sqrt{1 + 8x}}{2}$$
   For $n$ to be an integer, it is necessary and sufficient that:
   - $1 + 8x$ is a perfect square.
   - Since $1 + 8x$ is always odd, its square root will also always be odd, making $(-1 + \sqrt{1 + 8x})$ even and divisible by 2.
   Therefore, $x$ is a triangle number if and only if $1 + 8x$ is a perfect square. This enables an $O(1)$ arithmetic check.

2. **Parsing the Input File**:
   - Stream through the file character-by-character (using C's `fgetc` or C++'s standard streaming) to save memory.
   - Ignore double quotes (`"`).
   - Accrue letter values when matching letters `A`-`Z` ($c - \text{'A'} + 1$).
   - Upon encountering a comma (`,`) or end-of-file, check if the collected word value is a triangle number using our $O(1)$ mathematical test. If so, increment the counter.

## Complexity
- **Time**: $O(L)$ where $L$ is the total length of the file in characters (approx. 16KB) — extremely fast, completes in under 1 millisecond.
- **Space**: $O(1)$ auxiliary space, since it parses the input as a stream.

## Answer
$$\boxed{162}$$
