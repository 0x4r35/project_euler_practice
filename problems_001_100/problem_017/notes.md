# Problem 17: Number Letter Counts

## 1. Deconstructing the Rules
This is a counting problem disguised as a string manipulation problem. The key to solving it efficiently is breaking down the numbers into their core linguistic components. 

We can map the lengths of the foundational words:
* **1 to 9:** one (3), two (3), three (5), four (4), five (4), six (3), seven (5), eight (5), nine (4).
* **10 to 19:** These are unique in English and must be hardcoded. ten (3), eleven (6), twelve (6), thirteen (8), etc.
* **Tens (20, 30... 90):** twenty (6), thirty (6), forty (5 - *note: not 'fourty'*), etc.
* **Multipliers:** hundred (7), thousand (8).

## 2. The British "And" Rule
The problem specifies compliance with British usage, which means the word "and" (3 letters) is inserted between the hundreds place and the rest of the number, **unless** the number is an exact multiple of 100.
* **Correct:** 342 = "three hundred **and** forty-two"
* **Correct:** 115 = "one hundred **and** fifteen"
* **Correct:** 500 = "five hundred" *(no 'and')*

## 3. The Algorithmic Strategy
Instead of spelling out the words and counting the letters, which is slow and memory-intensive, we can map the *lengths* of the words directly to their integer values.

We build a recursive or conditional function:
1. **If $n < 20$:** Look up the exact length in a pre-made array.
2. **If $20 \le n < 100$:** Look up the length of the tens digit (`n / 10`) and add the length of the ones digit (`n % 10`).
3. **If $100 \le n < 1000$:** Add the length of the hundreds digit, plus 7 (for "hundred"). If `n % 100` is not zero, add 3 (for "and") and process the remainder.
4. **If $n = 1000$:** Add 11 ("one" + "thousand").