# Problem 29: Distinct Powers

## Approach
We need to find the number of distinct terms $a^b$ for $2 \le a \le 100$ and $2 \le b \le 100$.
In C++, we can use the prime factorization of $a$ and represent $a^b$ as a vector of prime exponents. Since $a \le 100$, we only need to keep track of the primes up to 97.
We iterate through all possible combinations of $a$ and $b$, calculate their prime exponent representation, and insert it into a `std::set`. The size of the set will give the number of distinct powers.
In C, we simulate the set behavior by storing all prime exponent arrays, sorting them, and then counting the distinct sequences.

## Complexity Analysis
- **Time Complexity:** $O(A \times B \times P \log(A \times B))$ where $A$ and $B$ are the ranges of bases and exponents (100), and $P$ is the number of primes under 100.
- **Space Complexity:** $O(A \times B \times P)$ to store the combinations.

## Learnings
Prime factorization provides an exact and reliable way to identify large powers without dealing with floating-point inaccuracies or BigInt libraries.
