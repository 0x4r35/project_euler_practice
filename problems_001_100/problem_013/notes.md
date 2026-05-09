# Problem 13: Large Sum

## 1. The Big Number Problem
A standard 32-bit integer in C and C++ can only hold numbers up to about 2 billion (10 digits). Even a massive 64-bit `long long` maxes out at roughly 9 quintillion (19 digits). 
So, how do we add numbers that are **50 digits long**? 

We have two main ways to solve this: The "Math Hack" and the "String Hack".

## 2. The Math Hack: Truncation (The Lazy & Smart Way)
The problem only asks for the **first 10 digits** of the final sum. It doesn't care about the last 40 digits.

Think about how addition works. When you add numbers, the numbers on the right carry over to the left. But how much can they actually carry over?
If you add 100 numbers together, the absolute maximum "carry-over" you can get from the missing digits is $100 \times 9 = 900$. 

This means if we just chop off the last 36 digits of every number and only add the **first 14 digits** together, the carry-over from the chopped pieces is too small to ever affect the first 10 digits of our final answer! 

A 14-digit number fits perfectly inside a standard `long long`, making the math incredibly fast and easy.

## 3. The String Hack: Arbitrary-Precision Arithmetic
If we actually needed the entire 50-digit answer, we would have to teach the computer how to add like a 3rd grader. 
We store the numbers not as math variables, but as **Strings of text**. 

Here is the algorithm:
1. Line up the strings on top of each other.
2. Look at the very last character of each string. 
3. Convert those characters to numbers (`'7' - '0' = 7`) and add them up.
4. If the sum is over 10, write down the last digit and "carry the 1" to the next column on the left.
5. Repeat until you run out of columns!

This is known as **Arbitrary-precision arithmetic** (or BigInt), and it allows computers to calculate numbers that are thousands or even millions of digits long.