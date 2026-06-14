#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

int card_value(char c) {
    if (c >= '2' && c <= '9') return c - '0';
    if (c == 'T') return 10;
    if (c == 'J') return 11;
    if (c == 'Q') return 12;
    if (c == 'K') return 13;
    if (c == 'A') return 14;
    return 0;
}

std::vector<int> evaluate(std::vector<int>& vals, std::vector<int>& suits) {
    std::vector<int> sorted = vals;
    std::sort(sorted.begin(), sorted.end(), std::greater<int>());

    int counts[15] = {0};
    for (int v : sorted) counts[v]++;

    std::vector<int> pair_vals, kickers;
    int three_val = 0, four_val = 0;
    int pairs = 0, three = 0, four = 0;

    for (int v = 14; v >= 2; v--) {
        if (counts[v] == 4) { four = 1; four_val = v; }
        else if (counts[v] == 3) { three = 1; three_val = v; }
        else if (counts[v] == 2) { pairs++; pair_vals.push_back(v); }
        else if (counts[v] == 1) { kickers.push_back(v); }
    }

    bool flush = true;
    for (int i = 1; i < 5; i++) {
        if (suits[i] != suits[0]) { flush = false; break; }
    }

    bool straight = false;
    int high_straight = 0;
    bool all_unique = true;
    for (int i = 1; i < 5; i++) {
        if (sorted[i] == sorted[i-1]) all_unique = false;
    }
    if (all_unique && sorted[0] - sorted[4] == 4) {
        straight = true;
        high_straight = sorted[0];
    }
    if (sorted[0] == 14 && sorted[1] == 5 && sorted[2] == 4 && sorted[3] == 3 && sorted[4] == 2) {
        straight = true;
        high_straight = 5;
    }

    std::vector<int> rank;
    if (straight && flush) {
        rank = {8, high_straight};
    } else if (four) {
        rank = {7, four_val, kickers[0]};
    } else if (three && pairs == 1) {
        rank = {6, three_val, pair_vals[0]};
    } else if (flush) {
        rank = {5};
        for (int v : sorted) rank.push_back(v);
    } else if (straight) {
        rank = {4, high_straight};
    } else if (three) {
        rank = {3, three_val, kickers[0], kickers[1]};
    } else if (pairs == 2) {
        int hi = std::max(pair_vals[0], pair_vals[1]);
        int lo = std::min(pair_vals[0], pair_vals[1]);
        rank = {2, hi, lo, kickers[0]};
    } else if (pairs == 1) {
        rank = {1, pair_vals[0], kickers[0], kickers[1], kickers[2]};
    } else {
        rank = {0};
        for (int v : sorted) rank.push_back(v);
    }

    while (rank.size() < 6) rank.push_back(0);
    return rank;
}

int main() {
    std::ifstream file("p054_poker.txt");
    if (!file.is_open()) {
        file.open("../../../p054_poker.txt");
        if (!file.is_open()) {
            std::cerr << "Cannot open p054_poker.txt\n";
            return 1;
        }
    }

    int wins = 0;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<std::string> cards(10);
        for (int i = 0; i < 10; i++) iss >> cards[i];

        std::vector<int> v1(5), s1(5), v2(5), s2(5);
        for (int i = 0; i < 5; i++) {
            v1[i] = card_value(cards[i][0]);
            s1[i] = cards[i][1];
            v2[i] = card_value(cards[i+5][0]);
            s2[i] = cards[i+5][1];
        }

        auto r1 = evaluate(v1, s1);
        auto r2 = evaluate(v2, s2);

        if (r1 > r2) wins++;
    }

    std::cout << wins << '\n';
    return 0;
}
