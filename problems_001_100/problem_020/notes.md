# Problem 20: Factorial Digit Sum

## 1. The Magnitude of 100!
The factorial of 100, written as $100!$, is the product of all positive integers less than or equal to 100:
$$100! = 100 \times 99 \times 98 \times \dots \times 3 \times 2 \times 1$$

To understand how massive this number is, $100!$ is roughly $9.33 \times 10^{157}$. It has exactly **158 digits**. 
Because a standard 64-bit integer (`long long` in C/C++) can only store numbers up to about 19 digits, standard multiplication will immediately overflow and fail. 

## 2. Arbitrary-Precision Multiplication (BigInt Array)
Just like in Problem 16 where we calculated $2^{1000}$, we must use an array to simulate grade-school multiplication. Instead of trying to hold the entire massive number in one mathematical variable, we break the number down so that each slot in an array holds exactly one digit.

**The Algorithm:**
1. Initialize an array representing the number `1` (which is $1!$).
2. Start a loop from $i = 2$ up to $100$.
3. Inside the loop, multiply *every single digit* currently in your array by $i$.
4. Just like on paper, if a number exceeds 9, you keep the "ones" place in the current array slot and "carry" the rest over to the next slot.

*Example ($4! \to 5!$):*
* $4! = 24$. In our array (stored backward for easier carrying), it looks like `[4, 2]`.
* Now we multiply by 5:
  * First digit: $4 \times 5 = 20$. Keep `0`, carry `2`. Array is now `[0, 2]`.
  * Second digit: $2 \times 5 = 10$, plus the carry of `2` = $12$. Keep `2`, carry `1`. Array is now `[0, 2]`.
  * We ran out of digits, but we still have a carry of `1`, so we tack it onto the end: `[0, 2, 1]`.
* Read backward, the array represents 120, which is exactly $5!$.

By letting the computer do this 100 times, the array will seamlessly grow to fit all 158 digits. Then, we simply sum them up!