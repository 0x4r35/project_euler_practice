#include <stdio.h>

int main() {
    const int gridSize = 20;
    // We need 21 intersections for a 20x20 grid of squares
    long long grid[21][21]; 

    // Initialize the top row and left column to 1 
    // (There is only 1 way to travel purely along the top edge or left edge)
    for (int i = 0; i <= gridSize; i++) {
        grid[i][0] = 1;
        grid[0][i] = 1;
    }

    // Dynamic Programming: A node's paths = the node above + the node to the left
    for (int i = 1; i <= gridSize; i++) {
        for (int j = 1; j <= gridSize; j++) {
            grid[i][j] = grid[i-1][j] + grid[i][j-1];
        }
    }

    printf("The number of paths through a 20x20 grid is: %lld\n", grid[gridSize][gridSize]);
    
    return 0;
}