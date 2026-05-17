# Problem 21: Amicable Numbers

## 1. Understanding Amicable Numbers
An amicable pair consists of two different numbers, $a$ and $b$, such that:
* The sum of the proper divisors of $a$ equals $b$ ($d(a) = b$).
* The sum of the proper divisors of $b$ equals $a$ ($d(b) = a$).
* And importantly, $a \neq b$ (a number is not amicable with itself).

Proper divisors are all numbers that divide evenly into $n$, excluding $n$ itself.
For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55, and 110. Their sum is 284.
The proper divisors of 284 are 1, 2, 4, 71, and 142. Their sum is 220.

## 2. The Algorithmic Strategy
To find the sum of all amicable numbers under 10000, we need two components:

1.  **An efficient divisor sum function:** We can optimize finding proper divisors by only looping up to the square root of $n$ ($\sqrt{n}$). When we find a divisor `i`, we also add its pair `n / i`. We must remember to start the sum at 1 (since 1 divides everything but isn't part of a pair like `n / 1 = n`, because proper divisors exclude $n$). We also need to be careful with perfect squares so we don't add the square root twice.
2.  **Iterating and Checking:** We loop through all numbers $a$ from 2 up to 9999.
    *   Calculate $b = d(a)$.
    *   To avoid double-counting pairs and ensure we are following the rules, we simply check: does $d(b)$ equal $a$, and is $a$ different from $b$?
    *   If both conditions are met, $a$ is an amicable number, and we add it to our running total.
