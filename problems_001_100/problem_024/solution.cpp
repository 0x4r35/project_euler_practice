#include <iostream>
#include <string>
#include <algorithm> //this is required for the std::next_permutation

int main() {
    //start with the very first permutation
    std::string digits = "0123456789";

    //we want the 1000000th permutation
    //since we are already looking at the first we need to step forward 999999times
    for (int i = 1; i < 1000000; i++) {
        std::next_permutation(digits.begin(), digits.end());

    }
    std::cout << "The millionth lexicographic permutation is: " << digits << std::endl;
    return 0;
}