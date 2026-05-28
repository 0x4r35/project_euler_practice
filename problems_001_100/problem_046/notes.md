# Goldbach's Other Conjecture (Project Euler Problem 46)

## The Problem
Christian Goldbach proposed that every odd composite number can be written as the sum of a prime and twice a square. We need to find the smallest odd composite number that disproves this conjecture. 

The mathematical representation of the conjecture is:
$n = p + 2k^2$

Where:
* $n$ is an odd composite number.
* $p$ is a prime number.
* $k$ is an integer greater than $0$.

## The Algorithm
1.  **Iterate Odd Numbers:** Begin at $n = 9$ (the first odd composite) and increment by 2.
2.  **Filter Composites:** Use a primality test to isolate only the composite numbers, skipping over primes.
3.  **Test the Conjecture:** For each identified composite number $n$, iterate through all primes $p$ where $p < n$.
4.  **Check for Squares:** For each prime $p$, check if there exists an integer $k \ge 1$ such that $p + 2k^2 = n$.
5.  **Identify the Exception:** If a composite number $n$ is found where no such combination of $p$ and $k$ exists, the loop breaks, and $n$ is printed as the counterexample to the conjecture.
