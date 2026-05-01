#include <iostream>
#include <string>

// Function to construct the literal string for a number
std::string number_to_words(int n) {
    const std::string ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
                                "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", 
                                "seventeen", "eighteen", "nineteen"};
    const std::string tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    
    if (n < 20) {
        return ones[n];
    }
    if (n < 100) {
        return tens[n / 10] + ones[n % 10];
    }
    if (n < 1000) {
        std::string result = ones[n / 100] + "hundred";
        if (n % 100 != 0) {
            result += "and" + number_to_words(n % 100);
        }
        return result;
    }
    if (n == 1000) {
        return "onethousand";
    }
    
    return "";
}

int main() {
    long long total_letters = 0;
    
    for (int i = 1; i <= 1000; ++i) {
        total_letters += number_to_words(i).length();
    }
    
    std::cout << "Total letters used from 1 to 1000: " << total_letters << std::endl;
    return 0;
}