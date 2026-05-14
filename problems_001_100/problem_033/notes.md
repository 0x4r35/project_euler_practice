# Project Euler Problem 33: Digit Cancelling Fractions

## Problem Analysis
We are looking for fractions $n/d$ such that:
1. $10 \le n < d < 100$ (two-digit numbers, strictly less than 1).
2. Trivial examples (e.g., multiples of 10 like $30/50$) are ignored.
3. If $n = 10a + b$ and $d = 10c + e$, removing a common digit from $n$ and $d$ yields a new fraction exactly equal to $n/d$.

There are four potential cases for cancelling a common digit:
1. $a = c$: $\frac{10a+b}{10a+e} = \frac{b}{e}$ (No valid solutions $< 1$)
2. $b = e$: $\frac{10a+b}{10c+b} = \frac{a}{c}$ (Only trivial solutions ending in 0)
3. $a = e$: $\frac{10a+b}{10c+a} = \frac{b}{c}$
4. $b = c$: $\frac{10a+b}{10b+e} = \frac{a}{e}$

## Finding the Fractions
Let's evaluate the most likely case ($b = c$):
$\frac{10a+b}{10b+e} = \frac{a}{e}$

Cross-multiplying to avoid floating point inaccuracies:
$e(10a + b) = a(10b + e)$
$10ae + be = 10ab + ae$
$9ae + be = 10ab$

By brute-forcing single digits $a, b, e$ where $a < b$ and $a < e$ to keep the fraction $<1$, we find exactly 4 valid combinations:
- 16 / 64 = 1 / 4
- 19 / 95 = 1 / 5
- 26 / 65 = 2 / 5
- 49 / 98 = 4 / 8  (or 1 / 2)

## Final Calculation
Product of the fractions:
$$ \frac{1}{4} \times \frac{1}{5} \times \frac{2}{5} \times \frac{1}{2} = \frac{2}{200} = \frac{1}{100} $$

In its lowest common terms, the denominator is **100**.
