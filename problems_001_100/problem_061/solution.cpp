#include <array>
#include <iostream>
#include <vector>

struct Figurate {
    int value;
    int prefix;
    int suffix;
};

constexpr int TYPES = 6;

std::array<std::vector<Figurate>, TYPES> numbers;
std::array<bool, TYPES> used{};
std::vector<int> chain;

int figurate(int sides, int n) {
    switch (sides) {
        case 3:
            return n * (n + 1) / 2;
        case 4:
            return n * n;
        case 5:
            return n * (3 * n - 1) / 2;
        case 6:
            return n * (2 * n - 1);
        case 7:
            return n * (5 * n - 3) / 2;
        case 8:
            return n * (3 * n - 2);
    }
    return 0;
}

void build_numbers() {
    for (int type = 0; type < TYPES; type++) {
        int sides = type + 3;

        for (int n = 1;; n++) {
            int value = figurate(sides, n);
            if (value >= 10000) {
                break;
            }
            if (value >= 1000 && value % 100 >= 10) {
                numbers[type].push_back({value, value / 100, value % 100});
            }
        }
    }
}

bool already_in_chain(int value) {
    for (int item : chain) {
        if (item == value) {
            return true;
        }
    }
    return false;
}

int chain_sum() {
    int total = 0;
    for (int value : chain) {
        total += value;
    }
    return total;
}

bool search() {
    if (chain.size() == 6) {
        return chain.back() % 100 == chain.front() / 100;
    }

    int next_prefix = chain.back() % 100;

    for (int type = 0; type < TYPES; type++) {
        if (used[type]) {
            continue;
        }

        used[type] = true;
        for (const Figurate& item : numbers[type]) {
            if (item.prefix != next_prefix || already_in_chain(item.value)) {
                continue;
            }

            chain.push_back(item.value);
            if (search()) {
                return true;
            }
            chain.pop_back();
        }
        used[type] = false;
    }

    return false;
}

int main() {
    build_numbers();

    used[5] = true;
    for (const Figurate& start : numbers[5]) {
        chain = {start.value};
        if (search()) {
            std::cout << chain_sum() << '\n';
            return 0;
        }
    }

    return 1;
}
