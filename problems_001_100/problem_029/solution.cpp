#include <iostream>
#include <set>
#include <vector>

int main() {
    std::set<std::vector<int>> s;
    for (int a = 2; a <= 100; ++a) {
        for (int b = 2; b <= 100; ++b) {
            std::vector<int> p(101, 0);
            int temp = a;
            for (int i = 2; i <= temp; ++i) {
                while (temp % i == 0) {
                    p[i] += b;
                    temp /= i;
                }
            }
            s.insert(p);
        }
    }
    std::cout << s.size() << "\n";
    return 0;
}
