# Problem 009 - Special Pythagorean triplet

## Approach
Brute forced pairs of `a` and `b` where $a < b$. Since $a + b + c = 1000$, we can compute $c$ directly and check if $a^2 + b^2 = c^2$.

## Complexity
- **Time:** $O(S^2)$ where $S = 1000$.
- **Space:** $O(1)$

