# Problem 18: Maximum Path Sum I

## 1. The Brute Force Trap ($O(2^n)$)
A naive approach to this problem is to simulate walking down the triangle, branching left or right at every step, and calculating the sum of every possible path to find the maximum. 
Since there are 14 rows below the top, you have to make a choice (Left or Right) 14 times. This means there are $2^{14} = 16,384$ possible routes. A computer can calculate 16k routes easily. However, Problem 67 has 100 rows, meaning $2^{99}$ routes. It would take billions of years to check them all! We need a smarter way.

## 2. The Clever Method: Bottom-Up Dynamic Programming ($O(n^2)$)
Instead of starting at the top and branching down, what if we start at the **bottom** and work our way up?

Look at the very bottom row, and the row just above it. For any number in the second-to-last row, you only have two choices of where to step next: directly below, or below and to the right. 
Naturally, you would choose the *bigger* of those two numbers to maximize your sum.

**The Algorithm:**
1. Start at the second-to-last row.
2. Look at the two numbers below each element.
3. Find the maximum of those two children, and *add it* to the parent.
4. Delete the bottom row.
5. Repeat this process, working your way up the triangle row by row.

By the time you reach the very top, the single number left will automatically be the maximum possible path sum! We only evaluate each number once, turning an impossible multi-billion-year problem into a calculation that finishes in less than a millisecond.