/*
 * Project Euler - Problem 039
 * Integer Right Triangles
 * https://projecteuler.net/problem=39
 *
 * Author: 0x4r35
 * Language: C++
 *
 * If p is the perimeter of a right angle triangle {a, b, c},
 * which value of p <= 1000 has the most solutions?
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> solutions(1001, 0);

    /*
     * For a right triangle: a^2 + b^2 = c^2 and a + b + c = p
     * So c = p - a - b, and a^2 + b^2 = (p - a - b)^2
     * Expanding and simplifying:
     * b = p*(p - 2a) / (2*(p - a))
     *
     * We need b to be a positive integer and a < b < c.
     */
    for (int p = 3; p <= 1000; p++) {
        for (int a = 1; a < p / 3; a++) {
            int numerator = p * (p - 2 * a);
            int denominator = 2 * (p - a);

            if (numerator % denominator == 0) {
                int b = numerator / denominator;
                int c = p - a - b;

                if (a < b && b < c)
                    solutions[p]++;
            }
        }
    }

    /* Find p with maximum solutions */
    auto it = max_element(solutions.begin(), solutions.end());
    int max_p = distance(solutions.begin(), it);

    cout << max_p << "\n";
    return 0;
}
