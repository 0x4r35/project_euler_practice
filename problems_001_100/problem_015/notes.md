# Problem 15: Lattice Paths

## 1. The Plain English Explanation
Imagine you are standing at the top-left corner of a city grid and need to get to the bottom-right corner. You are only allowed to walk **Right** or **Down**. 

If the city is a $2 \times 2$ grid of blocks, it takes exactly 4 steps to finish the journey no matter what path you take (e.g., Right, Right, Down, Down... or Down, Right, Down, Right). 
In a $20 \times 20$ grid, every single path will take exactly **40 steps** (20 steps Right, and 20 steps Down). 

Because every path requires exactly 20 "Rights", the entire problem boils down to a single question: *Out of my 40 total steps, which 20 of them will be "Right" moves?* Once you pick the 20 Right moves, the Down moves are forced into the remaining empty slots. 

## 2. The Math Stuff: Combinatorics
This is a classic combination problem. We need to "Choose 20 from 40", written mathematically as $\binom{40}{20}$.
The formula for combinations $\binom{n}{k}$ is:
$$ \frac{n!}{k!(n-k)!} $$

For our $20 \times 20$ grid:
$$ \frac{40!}{20! \times 20!} $$
Using this mathematical formula allows us to solve the problem in $O(N)$ time with a single loop, doing simple multiplication and division instead of tracking billions of paths!

## 3. The Computer Science Stuff: Dynamic Programming
If you don't want to use the combination formula, you can simulate the grid. 
Look at any intersection on the grid. How many ways can you get there? It is simply the number of ways to get to the intersection directly *above* it, PLUS the number of ways to get to the intersection directly to the *left* of it.

If we create a 2D array and systematically add the top cell to the left cell, the bottom-right corner will eventually hold the total number of possible paths. This technique of breaking a massive problem down into tiny overlapping sub-problems is called **Dynamic Programming**.
