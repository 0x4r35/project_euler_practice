# Problem 16: Power Digit Sum

## 1. The Integer Overflow Problem (Again!)
We are tasked with finding the sum of the digits of $2^{1000}$. 
To put this number in perspective, $2^{10}  pprox 10^3$ (1,000). 
Therefore, $2^{1000}  pprox (10^3)^{100} = 10^{300}$. 

This means our number will have roughly **302 digits**. A standard 64-bit `long long` integer can only hold about 19 digits before overflowing. If we try to calculate `pow(2, 1000)` using standard math variables, the computer will crash or return garbage data.

## 2. Arbitrary-Precision Arithmetic (The Array Method)
Just like in Problem 13, we must teach the computer how to do math exactly like a human does on a piece of paper. Instead of storing the number as one massive mathematical value, we store it as an **Array of single digits**.

Here is how the algorithm works:
1. Create an array and place the number `1` in the very first slot. (This represents $2^0$).
2. Loop 1000 times.
3. In each loop, multiply every single digit in your array by `2`.
4. If a digit becomes 10 or greater (e.g., $6 	imes 2 = 12$), you keep the ones place (`2`) in the current array slot, and "carry" the tens place (`1`) over to the next slot.

**Example calculating $2^4 	o 2^5$:**
* Array holding 16: `[6, 1]` (Note: it's easier for computers to store the number backward!)
* Multiply by 2: `[12, 2]`
* Carry the 1: `[2, 3]` -> Read backward, that is 32!

By doing this 1000 times, the array effortlessly expands to hold all 302 digits, and we simply add up the contents of the array at the end.
