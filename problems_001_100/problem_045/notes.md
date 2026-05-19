# Problem 45: Triangular, pentagonal, and hexagonal

## Approach
The problem asks for the next triangle number that is also pentagonal and hexagonal, after $T_{285} = P_{165} = H_{143} = 40755$.

First, observe that every hexagonal number is also a triangular number. 
For $H_m = m(2m-1)$, if we substitute $n = 2m-1$ in the triangular number formula $T_n = n(n+1)/2$, we get $T_{2m-1} = (2m-1)(2m)/2 = m(2m-1) = H_m$.
Therefore, we only need to iterate over hexagonal numbers starting from $m = 144$ and check if they are also pentagonal.

To check if a number $x$ is pentagonal, we use the inverse function: $n = (\sqrt{24x + 1} + 1) / 6$. If $n$ is an integer, then $x$ is pentagonal.

## Complexity
- Time Complexity: $O(1)$ effectively, since the answer is found very quickly (the next number is at $m = 27693$).
- Space Complexity: $O(1)$ as we only store a few variables.
