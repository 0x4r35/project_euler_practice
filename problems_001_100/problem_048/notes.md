# Project Euler Problem 48: Self Powers

## Problem Statement

The series, $1^1 + 2^2 + 3^3 + \dots + 10^{10} = 10405071317$.

**Goal**: Find the last ten digits of the series, $1^1 + 2^2 + 3^3 + \dots + 1000^{1000}$.

## Algorithmic Approach

To find the last ten digits of a massive number, we only need to perform all our calculations modulo $10^{10}$. Calculating the exact values of $n^n$ for large values of $n$ (such as $1000^{1000}$, which is a number with 3,001 digits) is computationally expensive and unnecessary. 

Instead, we rely on the properties of modular arithmetic:
* $(a + b) \pmod m = ((a \pmod m) + (b \pmod m)) \pmod m$
* $(a \times b) \pmod m = ((a \pmod m) \times (b \pmod m)) \pmod m$

### Execution

1.  **Define the Modulus**: We set our modulus to $10^{10}$ ($10,000,000,000$).
2.  **Iterate and Exponentiate**: For each integer $i$ from 1 to 1000, we compute $i^i \pmod{10^{10}}$.
    * Because $i \le 1000$ and the running term is kept below $10^{10}$, the maximum value during multiplication is $10^{13}$. This easily fits within a standard 64-bit integer (`unsigned long long` in C), avoiding the need for `__int128` or big integer libraries.
3.  **Accumulate**: We add the result of $i^i \pmod{10^{10}}$ to our running sum, also taking the modulo $10^{10}$ after each addition.

## Complexity Analysis

* **Time Complexity**: $\mathcal{O}(N^2)$ where $N = 1000$. The outer loop runs 1000 times, and the inner naive exponentiation loop runs up to 1000 times. This results in exactly 500,500 operations, which resolves in less than a millisecond in C. (Could be optimized to $\mathcal{O}(N \log N)$ using binary exponentiation, but is practically unnecessary for limits this small).
* **Space Complexity**: $\mathcal{O}(1)$. We only need to store the running sum and the current term, operating entirely within standard 64-bit integer bounds.