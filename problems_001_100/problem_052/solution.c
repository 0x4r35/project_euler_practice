#include <stdio.h>
#include <stdbool.h>

void digit_signature(int n, int sig[10]) {
    for (int i = 0; i < 10; i++) sig[i] = 0;
    while (n > 0) {
        sig[n % 10]++;
        n /= 10;
    }
}

bool same_digits(int a, int b) {
    int sa[10], sb[10];
    digit_signature(a, sa);
    digit_signature(b, sb);
    for (int i = 0; i < 10; i++) {
        if (sa[i] != sb[i]) return false;
    }
    return true;
}

int main() {
    for (int x = 1; ; x++) {
        bool valid = true;
        for (int m = 2; m <= 6; m++) {
            if (!same_digits(x, x * m)) {
                valid = false;
                break;
            }
        }
        if (valid) {
            printf("%d\n", x);
            return 0;
        }
    }
    return 0;
}
