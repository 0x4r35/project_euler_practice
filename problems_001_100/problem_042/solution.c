/*
 * Project Euler - Problem 042
 * Coded Triangle Numbers
 * https://projecteuler.net/problem=42
 *
 * Author: 0x4r35
 * Language: C
 *
 * How many words in the words.txt file are triangle words?
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Check if a number is a triangle number
bool is_triangle_number(int x) {
    if (x <= 0) return false;
    long long val = 1 + 8LL * x;
    long long root = (long long)round(sqrt(val));
    return root * root == val;
}

int main() {
    FILE *infile = fopen("words.txt", "r");
    if (!infile) {
        infile = fopen("problems_001_100/problem_042/words.txt", "r");
    }
    if (!infile) {
        fprintf(stderr, "Error: Could not open words.txt\n");
        return 1;
    }

    int triangle_word_count = 0;
    int current_word_val = 0;
    int c;

    while ((c = fgetc(infile)) != EOF) {
        if (c == '"') {
            continue;
        } else if (c == ',') {
            if (current_word_val > 0) {
                if (is_triangle_number(current_word_val)) {
                    triangle_word_count++;
                }
                current_word_val = 0;
            }
        } else if (c >= 'A' && c <= 'Z') {
            current_word_val += (c - 'A' + 1);
        }
    }

    // Check the last word in the file
    if (current_word_val > 0) {
        if (is_triangle_number(current_word_val)) {
            triangle_word_count++;
        }
    }

    fclose(infile);
    printf("%d\n", triangle_word_count);
    return 0;
}
