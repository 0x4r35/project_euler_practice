#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::ifstream file("p022_names.txt");
    if (!file.is_open()) {
        std::cerr << "Error: Could not open p022_names.txt" << std::endl;
        return 1;
    }

    std::vector<std::string> names;
    std::string name;

    // Read until a comma is found
    while (std::getline(file, name, ',')) {
        // Remove the surrounding quotes
        name.erase(std::remove(name.begin(), name.end(), '"'), name.end());
        names.push_back(name);
    }
    file.close();

    // Sort the vector alphabetically
    std::sort(names.begin(), names.end());

    long long total_score = 0;

    for (size_t i = 0; i < names.size(); ++i) {
        int alpha_val = 0;
        // Loop through each character in the string
        for (char c : names[i]) {
            alpha_val += c - 'A' + 1; // ASCII math
        }
        
        // Multiply alphabetical value by its position (index + 1)
        total_score += alpha_val * (i + 1);
    }

    std::cout << "Total of all name scores: " << total_score << std::endl;
    return 0;
}