#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 32

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

int main(void) {
    int total = 0;

    for (int base = 1; base <= 9; base++) {
        BigNum value;
        set_one(&value);

        for (int exponent = 1;; exponent++) {
            multiply(&value, base);

            if (value.len == exponent) {
                total++;
            }
            if (value.len < exponent) {
                break;
            }
        }
    }

    printf("%d\n", total);
    return 0;
}
