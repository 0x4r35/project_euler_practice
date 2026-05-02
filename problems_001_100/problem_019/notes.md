# Problem 19: Counting Sundays

## 1. Zeller's Congruence vs. Simulation
To find the day of the week for any given date, mathematicians often use **Zeller's Congruence**, a famous algorithm. However, for a continuous sequence of months over a century, a simple **Simulation** (keeping a running tally of the days) is actually easier to write and just as fast for a computer.

## 2. The Modulo Operator (`%`)
The secret weapon for calendar math is the modulo operator. Since a week repeats every 7 days, we can represent days as numbers (e.g., Sunday = 0, Monday = 1... Saturday = 6). 
If today is Tuesday (2), and a month has 31 days, what day is the 1st of the next month?
$$(2 + 31) \pmod 7 = 33 \pmod 7 = 5 \text{ (Friday)}$$

## 3. The Leap Year Rules
The problem provides the exact logic needed for leap years:
1. A year is a leap year if it is evenly divisible by 4.
2. **Except** if it is a century year (divisible by 100), then it is *not* a leap year.
3. **Unless** it is also divisible by 400, then it *is* a leap year.

*Example:* 1900 is divisible by 4, but it is a century. It is not divisible by 400. Therefore, 1900 is **not** a leap year (February has 28 days). The year 2000 is divisible by 400, so it **is** a leap year.

## 4. The Setup
The problem asks for Sundays between **1 Jan 1901** and **31 Dec 2000**.
We are given that **1 Jan 1900** was a Monday. 
We must first simulate the 12 months of 1900 to find out what day of the week **1 Jan 1901** was (which is a Tuesday). From there, we start our count!