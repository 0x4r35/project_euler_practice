# Problem 23: Non-Abundant Sums

## 1. Finding Divisors Efficiently (The Sieve Method)
We need to find the sum of proper divisors for all numbers up to 28,123. Doing this naively for each number using trial division takes way too long. Instead, we use a "Sieve" approach (similar to the Sieve of Eratosthenes used for prime numbers). 
We iterate a variable $i$ from 1 to $N/2$, and add $i$ to the sum tally of all multiples of $i$. This computes the sum of proper divisors for every number simultaneously in $O(N \log N)$ time!

## 2. Abundant Numbers List
Once we have an array of divisor sums, we simply filter out the numbers where `divisor_sum > number` and store them in an `abundant_numbers` array. (The problem notes that 12 is the smallest abundant number).

## 3. The Boolean Array Strategy
To find which numbers can be formed by the sum of two abundant numbers, we create a boolean array `can_be_written` of size 28,124, initialized entirely to `false`.
We then use a nested loop to pair up every number in our `abundant_numbers` list. If their sum `num1 + num2 <= 28123`, we set `can_be_written[num1 + num2] = true`.

## 4. The Final Calculation
Finally, we loop from 1 to 28,123. If `can_be_written[i]` is still `false`, it means it's mathematically impossible to form this number using two abundant numbers. We add $i$ to our final total!