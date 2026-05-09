# Contributing Guide

## How to Add a New Solution

1. Navigate to the correct section folder (`problems_001_100/`, `problems_101_200/`, or `problems_201_300/`)
2. Create a new directory: `problem_XXX/` (zero-padded to 3 digits)
3. Add your files:
   - `solution.c` — C solution
   - `solution.cpp` — C++ solution  
   - `notes.md` — Your approach, complexity analysis, and learnings

## Compilation

### C
```bash
gcc -o solution solution.c -lm -Wall -Wextra
./solution
```

### C++
```bash
g++ -o solution solution.cpp -lm -Wall -Wextra -std=c++17
./solution
```

## Code Style
- Use meaningful variable names
- Add comments explaining your mathematical approach
- Include time and space complexity in `notes.md`
- Follow the header template in existing solutions
