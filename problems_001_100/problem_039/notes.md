# Project Euler Problem 39: Integer Right Triangles

## Problem Statement
If $p$ is the perimeter of a right angle triangle with integral length sides $\{a, b, c\}$, for which value of $p \leq 1000$ is the number of solutions maximised?

## Approach
1. **Algebraic Simplification**: From $a^2 + b^2 = c^2$ and $a + b + c = p$, substitute $c = p - a - b$:

   $$a^2 + b^2 = (p - a - b)^2$$

   Expanding and simplifying yields:

   $$b = \frac{p(p - 2a)}{2(p - a)}$$

2. **Iterate**: For each perimeter $p$ from 3 to 1000, iterate over possible values of $a$ from 1 to $p/3$ (since $a < b < c$ implies $a < p/3$).
3. **Check**: If $b$ is a positive integer (numerator divisible by denominator) and $a < b < c$, count this as a valid solution.
4. **Maximize**: Track which $p$ has the most valid Pythagorean triplets.

## Key Observations
- The algebraic reduction to a single variable ($a$) avoids the need for a triple nested loop.
- The constraint $a < b < c$ prevents counting duplicate triplets.
- Perimeters divisible by many small factors tend to have more solutions — highly composite numbers shine here.

## Complexity
- **Time**: $O(p_{max}^2 / 3)$ ≈ $O(333000)$ iterations — very fast.
- **Space**: $O(p_{max})$ for the solutions count array.

## Answer
$$\boxed{840}$$
