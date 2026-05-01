# Problem 011 - Largest product in a grid

## Approach
Used a straightforward iteration over all possible $1 \times 4$ sequences in the $20 \times 20$ grid. For each valid starting position, calculated the product in four directions: horizontally (right), vertically (down), diagonally (down-right), and anti-diagonally (down-left).

## Complexity
- **Time:** $O(N^2)$ where $N = 20$.
- **Space:** $O(N^2)$ to store the grid.
