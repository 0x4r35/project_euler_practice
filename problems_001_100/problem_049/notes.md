# Project Euler Problem 49: Prime Permutations

## Problem Statement

The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: 
(i) each of the three terms are prime, and, 
(ii) each of the 4-digit numbers are permutations of one another.

There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.

**Goal**: What 12-digit number do you form by concatenating the three terms in this sequence?

## Algorithmic Approach

To solve this efficiently, we can break the problem down into manageable steps: finding primes, generating permutations, and checking for arithmetic sequences.

### 1. Generating Primes (Sieve of Eratosthenes)
First, we need to identify all prime numbers. Since the problem specifically asks for 4-digit numbers, we only care about primes in the range from 1000 to 9999. A simple Sieve of Eratosthenes up to 10,000 is perfect for this. We can use a boolean array `isPrime` where `isPrime[i]` is true if `i` is prime.

### 2. Identifying Permutations
We need a robust way to check if two numbers are permutations of each other. The most foolproof method for digits is to sort the digits of each number and compare the sorted strings.
For example:
* `1487` sorted becomes `"1478"`
* `4817` sorted becomes `"1478"`
* `8147` sorted becomes `"1478"`
Since they all sort to the same string, they are permutations. We can create a helper function `are_permutations(a, b)` that handles this digit extraction and comparison.

### 3. Finding the Sequence
With our primes and permutation checker ready, we can search for the sequence:
1.  Iterate through all 4-digit primes (let's call the current prime $P_1$).
2.  Iterate through possible step sizes (let's call the step $d$). Since $P_1$ is at least 1000, and $P_3 = P_1 + 2d$ must be strictly less than 10000, the maximum step size is $rac{10000 - 1000}{2} = 4500$.
3.  Calculate the next two terms in the potential sequence: 
    * $P_2 = P_1 + d$
    * $P_3 = P_1 + 2d$
4.  Check our constraints:
    * Are both $P_2$ and $P_3$ primes? (Using our `isPrime` array).
    * Is $P_2$ a permutation of $P_1$?
    * Is $P_3$ a permutation of $P_1$?
5.  If all conditions are met, and the sequence is not the known one (1487, 4817, 8147), we have found our answer.

## Complexity Analysis

* **Time Complexity**: $\mathcal{O}(N 	imes D)$ where $N$ is the number of 4-digit primes (approx 1061) and $D$ is the maximum step size (approx 4500). The Sieve is $\mathcal{O}(M \log \log M)$ where $M = 10000$. The permutation check involves sorting small 4-element arrays, which is negligible $\mathcal{O}(1)$. Overall, the nested loops will execute around $1000 \times 4500 = 4.5 \times 10^6$ times in the worst case, making the time complexity well within milliseconds in C.
* **Space Complexity**: $\mathcal{O}(M)$ where $M = 10000$. We need an array of size 10000 to store the boolean sieve, which takes practically zero memory (10KB).