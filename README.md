<div align="center">

# Project Euler Practice

![Build Status](https://github.com/0x4r35/project_euler_practice/actions/workflows/build.yml/badge.svg)
![Language C](https://img.shields.io/badge/Language-C-blue?logo=c&logoColor=white)
![Language C++](https://img.shields.io/badge/Language-C++-00599C?logo=cplusplus&logoColor=white)
![License MIT](https://img.shields.io/github/license/0x4r35/project_euler_practice?color=green)
![Problems](https://img.shields.io/badge/Problems-300-orange)

**C & C++ practice with the help of [projecteuler.net](https://projecteuler.net) and advanced maths concepts**

*I love maths and programming — special thanks to [Project Euler](https://projecteuler.net) for amazing learning challenges!*  
*This repo will be updated with time. If you have a better method or solution, please teach me your way!*

---

</div>

## Repository Structure

```
project_euler_practice/
│
├── problems_001_100/             <- Beginner to Intermediate
│   ├── problem_001/
│   │   ├── solution.c            <- C solution
│   │   ├── solution.cpp          <- C++ solution
│   │   └── notes.md              <- Approach & learnings
│   ├── problem_002/
│   └── ...
│
├── problems_101_200/             <- Intermediate to Advanced
│   ├── problem_101/
│   └── ...
│
├── problems_201_300/             <- Advanced to Expert
│   ├── problem_201/
│   └── ...
│
├── .github/workflows/build.yml   <- CI: auto-compiles all solutions
├── .gitignore                    <- Ignores compiled binaries & IDE files
├── CONTRIBUTING.md               <- How to add solutions
├── LICENSE                       <- MIT License
└── README.md                     <- You are here!
```

## Quick Start

### Compile & Run a C Solution
```bash
cd problems_001_100/problem_001
gcc -o solution solution.c -lm -Wall -Wextra
./solution
```

### Compile & Run a C++ Solution
```bash
cd problems_001_100/problem_001
g++ -o solution solution.cpp -lm -Wall -Wextra -std=c++17
./solution
```

## Progress

| Section | Range | Difficulty | Status |
|---------|-------|------------|--------|
| [Section 1](./problems_001_100/) | 001 – 100 | Beginner to Intermediate | In Progress |
| [Section 2](./problems_101_200/) | 101 – 200 | Intermediate to Advanced | Upcoming |
| [Section 3](./problems_201_300/) | 201 – 300 | Advanced to Expert | Upcoming |

## Tech Stack

| Tool | Purpose |
|------|---------|
| **GCC** | C compiler |
| **G++** | C++ compiler (C++17) |
| **GitHub Actions** | CI — auto-build on every push |
| **Project Euler** | Problem source |

## Solution Template

When adding a new solution, create a folder `problem_XXX/` inside the appropriate section and include:

```c
/*
 * Project Euler - Problem XXX
 * <Problem Title>
 * https://projecteuler.net/problem=XXX
 *
 * Author: 0x4r35
 * Language: C
 */

#include <stdio.h>

int main() {
    // Your solution here
    return 0;
}
```

## Contributing

See [CONTRIBUTING.md](./CONTRIBUTING.md) for guidelines.

## License

This project is licensed under the MIT License — see [LICENSE](./LICENSE) for details.

## C++ resources 
https://github.com/RedSkittleFox/Cpp-Learning-Resources

---

<div align="center">

*Happy Problem Solving!*

</div>
