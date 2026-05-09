# Problem 24: Lexicographic Permutations

## 1. What is a Lexicographic permutation ?
A permutation is just an arrangement of objects. "Lexicographic" simply means dictionary or alphabetical order. 
For the digits 0, 1, and 2, the lexicographic permutations are:
`012`, `021`, `102`, `120`, `201`, `210`.

There are $10!$ (10 factorial) possible permutations of the digits 0 through 9, which equals **3,628,800** total combinations.

## 2. Approach 1: The Standard Library (Brute Force)
In modern languages like C++, the standard library provides a built-in function called `std::next_permutation`. It takes an array or string and effortlessly rearranges it into the next lexicographical order. 
Since a computer can process millions of operations in a fraction of a second, we can literally just start with "0123456789" and call this function 999,999 times! 

## 3. Approach 2: Factoradics (The Math Way)
If you want to solve this without iterating a million times, you can use math to jump directly to the answer in exactly 10 steps. This is based on the **Factorial Number System** (Factoradics).

Think about how the permutations are grouped. Out of the 3,628,800 permutations:
* Exactly $9!$ ($362,880$) of them start with **0**.
* Exactly $9!$ ($362,880$) of them start with **1**.
* Exactly $9!$ ($362,880$) of them start with **2**.

We want the 1,000,000th permutation. Because permutations are normally 1-indexed, we shift our target to be 0-indexed: **999,999**.
* If we divide $999,999 / 362,880$, we get $2$ with a remainder.
* This tells us the first digit is located at **Index 2** of our available numbers `[0, 1, 2, 3...]`. 
* The number at Index 2 is **2**.
* We remove **2** from our pool, take the remainder ($274,239$), and divide it by $8!$ to find the next digit's index. We repeat this process until we run out of digits!