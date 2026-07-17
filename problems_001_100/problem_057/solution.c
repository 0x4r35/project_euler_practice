#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 500

typedef struct {
    int digits[MAX_DIGITS];
    int len;
} BigNum;

BigNum from_int(int value) {
    BigNum n;
    memset(n.digits, 0, sizeof(n.digits));
    n.len = 0;
    if (value == 0) {
        n.digits[n.len++] = 0;
    }
    while (value > 0) {
        n.digits[n.len++] = value % 10;
        value /= 10;
    }
    return n;
}

BigNum add(BigNum a, BigNum b) {
    BigNum result;
    memset(result.digits, 0, sizeof(result.digits));
    result.len = 0;

    int carry = 0;
    int max_len = a.len > b.len ? a.len : b.len;
    for (int i = 0; i < max_len || carry; i++) {
        int sum = carry;
        if (i < a.len) sum += a.digits[i];
        if (i < b.len) sum += b.digits[i];
        result.digits[result.len++] = sum % 10;
        carry = sum / 10;
    }

    return result;
}

int main() {
    BigNum numerator = from_int(3);
    BigNum denominator = from_int(2);
    int count = 0;

    for (int i = 1; i <= 1000; i++) {
        if (numerator.len > denominator.len) {
            count++;
        }

        BigNum next_numerator = add(numerator, add(denominator, denominator));
        BigNum next_denominator = add(numerator, denominator);
        numerator = next_numerator;
        denominator = next_denominator;
    }

    printf("%d\n", count);
    return 0;
}
