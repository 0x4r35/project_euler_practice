# Problem 22: Names Scores

## 1. Data Parsing and Sanitization
Before we can perform any math, we have to extract the data from `names.txt`. The file is formatted as a single line of comma-separated strings enclosed in quotes:
`"MARY","PATRICIA","LINDA","BARBARA",...`

In a language like C++, we can read the file stream, use a delimiter (like the comma) to separate the names, and then strip out the quotation marks `"` to get clean strings.

## 2. Alphabetical Sorting (Lexicographical Order)
Once the data is clean and stored in an array or list, we must sort it alphabetically. 
* In C, we can use the built-in `qsort()` function combined with `strcmp()`.
* In C++, we can rely on `std::sort()`, which automatically sorts vectors of strings in lexicographical (alphabetical) order out of the box.

## 3. ASCII Character Math
Computers don't inherently know that 'A' is the 1st letter of the alphabet and 'Z' is the 26th. Instead, computers use the **ASCII** encoding standard, where every character is mapped to a specific integer.
* The ASCII value for 'A' is 65.
* The ASCII value for 'B' is 66, and so on.

To convert a character into its alphabetical position (1-26), we can simply subtract the ASCII value of 'A' (65) and add 1.
*Formula:* `Char_Value = character - 'A' + 1`

## 4. The Final Calculation
With our sorted array and our ASCII trick ready, the rest is simple:
1. Loop through the sorted array. The `position` of a name is just its index + 1.
2. Loop through each character of the name, applying our ASCII formula to calculate the `alphabetical_value`.
3. Multiply the `position` by the `alphabetical_value` to get the `name_score`.
4. Add the `name_score` to a running total!