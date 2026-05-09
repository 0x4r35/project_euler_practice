# Notes on Digit Cancelling Fractions (Project Euler 33)

## Problem Understanding
We are looking for fractions $n/d$ such that:
1. $10 \le n < d < 100$ (two-digit numbers, strictly less than 1).
2. "Trivial" fractions like $30/50 = 3/5$ are ignored. We skip cases where the denominator is a multiple of 10.
3. An "incorrect" cancellation of a common digit in the numerator and denominator yields the correct simplified fraction.

## Mathematical Logic
Let the numerator be $n = 10 \cdot n_1 + n_0$ and the denominator be $d = 10 \cdot d_1 + d_0$, where $n_1, n_0, d_1, d_0$ are digits.

Since $n < d$, we only iterate $n$ from 10 to $d-1$.

There are two main cases for non-trivial digit cancellation:
* **Case 1: The units digit of $n$ equals the tens digit of $d$ ($n_0 == d_1$).**
    If we cancel this digit, the resulting fraction is $n_1 / d_0$.
    We check if the values are equivalent: $\frac{n}{d} = \frac{n_1}{d_0}$.
    To avoid floating-point inaccuracies, we cross-multiply: $n \cdot d_0 == d \cdot n_1$.

* **Case 2: The tens digit of $n$ equals the units digit of $d$ ($n_1 == d_0$).**
    If we cancel this digit, the resulting fraction is $n_0 / d_1$.
    We check equivalence via cross-multiplication: $n \cdot d_1 == d \cdot n_0$.

*(Note: The other combinations $n_0 = d_0$ and $n_1 = d_1$ either lead to trivial cases or impossibility given $n < d$)*.

## Algorithm Steps
1. Initialize `num_prod = 1` and `den_prod = 1` to keep track of the product of the four fractions.
2. Loop $d$ from 11 to 99. If $d \pmod{10} == 0$, `continue` (skip trivial cases).
3. Loop $n$ from 10 to $d - 1$.
4. Extract the digits $n_1, n_0, d_1, d_0$.
5. Test Case 1 and Case 2 using the cross-multiplication logic.
6. If a match is found, multiply $n$ to `num_prod` and $d$ to `den_prod`.
7. After finding all four fractions, calculate the Greatest Common Divisor (GCD) of `num_prod` and `den_prod`.
8. The answer is the simplified denominator: `den_prod / gcd(num_prod, den_prod)`.

## Complexity
* **Time Complexity:** $O(1)$ effectively, since the search space is strictly bounded by a constant (from $11$ to $99$, roughly $4000$ loop iterations total).
* **Space Complexity:** $O(1)$ as only a few variables are used to store products and digits.
