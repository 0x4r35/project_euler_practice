/*
 * Project Euler - Problem 042
 * Coded Triangle Numbers
 * https://projecteuler.net/problem=42
 *
 * Author: 0x4r35
 * Language: C++
 *
 * How many words in the words.txt file are triangle words?
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// Check if a number is a triangle number
bool is_triangle_number(int x) {
    if (x <= 0) return false;
    long long val = 1 + 8LL * x;
    long long root = round(sqrt(val));
    return root * root == val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream infile("words.txt");
    if (!infile.is_open()) {
        infile.open("problems_001_100/problem_042/words.txt");
    }
    if (!infile.is_open()) {
        cerr << "Error: Could not open words.txt\n";
        return 1;
    }

    string content;
    getline(infile, content);
    infile.close();

    int triangle_word_count = 0;
    string current_word = "";
    
    for (char c : content) {
        if (c == '"') {
            continue;
        } else if (c == ',') {
            if (!current_word.empty()) {
                int value = 0;
                for (char letter : current_word) {
                    value += (letter - 'A' + 1);
                }
                if (is_triangle_number(value)) {
                    triangle_word_count++;
                }
                current_word = "";
            }
        } else {
            current_word += c;
        }
    }
    
    // Check the last word in the file
    if (!current_word.empty()) {
        int value = 0;
        for (char letter : current_word) {
            value += (letter - 'A' + 1);
        }
        if (is_triangle_number(value)) {
            triangle_word_count++;
        }
    }

    cout << triangle_word_count << "\n";
    return 0;
}
