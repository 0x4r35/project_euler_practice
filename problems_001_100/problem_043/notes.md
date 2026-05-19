# Problem 43: Sub-string divisibility

## Approach
The problem requires finding the sum of all 0 to 9 pandigital numbers with a specific sub-string divisibility property.
Since a 0 to 9 pandigital number has 10 digits, we can generate all permutations of the digits '0' to '9' using `std::next_permutation`.
For each permutation, we check the divisibility condition:
- d2d3d4 divisible by 2
- d3d4d5 divisible by 3
- d4d5d6 divisible by 5
- d5d6d7 divisible by 7
- d6d7d8 divisible by 11
- d7d8d9 divisible by 13
- d8d9d10 divisible by 17

To optimize, we can quickly skip permutations that don't satisfy the condition (e.g., d4 must be even, d6 must be 0 or 5).
Actually, generating all 10! = 3,628,800 permutations and checking the conditions is very fast in C++ and takes less than a second.

## Complexity
- Time Complexity: O(10!) since we generate all permutations of 10 digits. The checking takes O(1) time. Overall time is well within limits.
- Space Complexity: O(1) as we only use a string of 10 characters to store the permutations and a few variables for calculating the sum.
