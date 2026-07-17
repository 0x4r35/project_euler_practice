#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 250

typedef struct {
    int digits[MAX_DIGITS];
    int len;
} BigNum;

void set_one(BigNum *n) {
    memset(n->digits, 0, sizeof(n->digits));
    n->digits[0] = 1;
    n->len = 1;
}

void multiply(BigNum *n, int factor) {
    int carry = 0;
    for (int i = 0; i < n->len; i++) {
        int product = n->digits[i] * factor + carry;
        n->digits[i] = product % 10;
        carry = product / 10;
    }
    while (carry > 0) {
        n->digits[n->len++] = carry % 10;
        carry /= 10;
    }
}

int digit_sum(const BigNum *n) {
    int sum = 0;
    for (int i = 0; i < n->len; i++) {
        sum += n->digits[i];
    }
    return sum;
}

int main() {
    int best = 0;

    for (int a = 1; a < 100; a++) {
        BigNum value;
        set_one(&value);
        for (int b = 1; b < 100; b++) {
            multiply(&value, a);
            int sum = digit_sum(&value);
            if (sum > best) {
                best = sum;
            }
        }
    }

    printf("%d\n", best);
    return 0;
}
