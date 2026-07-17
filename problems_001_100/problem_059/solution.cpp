#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<int> load_codes() {
    const std::vector<std::string> paths = {
        "p059_cipher.txt",
        "problems_001_100/problem_059/p059_cipher.txt"
    };

    std::ifstream file;
    for (const auto& path : paths) {
        file.open(path);
        if (file.is_open()) break;
        file.clear();
    }

    std::vector<int> codes;
    std::string token;
    while (std::getline(file, token, ',')) {
        if (!token.empty()) {
            codes.push_back(std::stoi(token));
        }
    }
    return codes;
}

bool is_allowed_plaintext(int ch) {
    return ch == '\n' || (ch >= 32 && ch <= 126);
}

int count_word(const std::string& text, const std::string& word) {
    int count = 0;
    std::size_t pos = text.find(word);
    while (pos != std::string::npos) {
        count++;
        pos = text.find(word, pos + 1);
    }
    return count;
}

int score_text(const std::string& text) {
    int score = 0;
    for (unsigned char raw : text) {
        char c = static_cast<char>(std::tolower(raw));
        if (c == ' ') score += 6;
        else if (std::string("etaoinshrdlu").find(c) != std::string::npos) score += 3;
        else if (c >= 'a' && c <= 'z') score += 1;
    }

    score += 40 * count_word(text, " the ");
    score += 25 * count_word(text, " and ");
    score += 20 * count_word(text, " of ");
    score += 20 * count_word(text, " to ");
    score += 15 * count_word(text, " in ");
    return score;
}

int main() {
    std::vector<int> codes = load_codes();
    if (codes.empty()) {
        std::cerr << "Cannot open p059_cipher.txt\n";
        return 1;
    }

    int best_score = -1;
    int best_sum = 0;

    for (char a = 'a'; a <= 'z'; a++) {
        for (char b = 'a'; b <= 'z'; b++) {
            for (char c = 'a'; c <= 'z'; c++) {
                const char key[3] = {a, b, c};
                std::string text;
                int sum = 0;
                bool valid = true;

                for (std::size_t i = 0; i < codes.size(); i++) {
                    int plain = codes[i] ^ key[i % 3];
                    if (!is_allowed_plaintext(plain)) {
                        valid = false;
                        break;
                    }
                    text.push_back(static_cast<char>(plain));
                    sum += plain;
                }
                if (!valid) continue;

                int score = score_text(text);
                if (score > best_score) {
                    best_score = score;
                    best_sum = sum;
                }
            }
        }
    }

    std::cout << best_sum << '\n';
    return 0;
}
