# Problem 14: Longest Collatz Sequence

## 1. The Collatz Conjecture (The 3n + 1 Problem)
The Collatz Conjecture is one of the most famous unsolved problems in mathematics. The rules are simple:
* If n is even, divide it by 2: n to n/2
* If n is odd, multiply by 3 and add 1: n \to 3n + 1

The conjecture states that no matter what positive integer you start with, the sequence will always eventually reach 1. Mathematicians have tested numbers up to 2^{68}, and they all reach 1, but nobody has been able to *prove* it is true for infinity!

## 2. The Integer Overflow Trap (Again!)
The problem states we are checking starting numbers under 1,000,000. However, the sequence can wildly spike up and down. 
For example, if you start with `113,383`, the sequence spikes all the way up to `2,482,111,348` before crashing back down to 1. 

A standard 32-bit signed integer has a maximum limit of `2,147,483,647`. If we use a standard `int` to hold the current number in our sequence, it will overflow, turn into a negative number, and crash our program. 
**Rule:** Always use a 64-bit integer (`long long` in C/C++) to track the current  nduring a Collatz calculation.

## 3. The Optimization: Memoization (Caching)
A brute-force approach calculates the chain for every number from scratch. But look at what happens if we calculate 13:
13 to 40 to 20 to 10 to 5 to 16 to 8 to 4 to 2 to 1

Later, when our loop reaches the number `20`, we don't need to calculate 20 to 10 to 5 dots all over again! If we save the length of `13`'s chain in an array, we can just look it up.
By creating an array of 1,000,000 slots and saving the sequence lengths as we find them, we can drastically reduce the amount of math the computer has to do. This technique of saving previous answers to speed up future calculations is called **Memoization**.
