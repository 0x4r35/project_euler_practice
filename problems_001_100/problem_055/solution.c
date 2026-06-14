#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 200

typedef struct {
    int d[MAX_DIGITS];
    int len;
} BigNum;

BigNum from_long(long long n) {
    BigNum b;
    b.len = 0;
    if (n == 0) { b.d[0] = 0; b.len = 1; return b; }
    while (n > 0) {
        b.d[b.len++] = n % 10;
        n /= 10;
    }
    return b;
}

BigNum add(BigNum a, BigNum b) {
    BigNum c;
    int carry = 0;
    int max = a.len > b.len ? a.len : b.len;
    c.len = 0;
    for (int i = 0; i < max || carry; i++) {
        int sum = carry;
        if (i < a.len) sum += a.d[i];
        if (i < b.len) sum += b.d[i];
        c.d[c.len++] = sum % 10;
        carry = sum / 10;
    }
    return c;
}

BigNum reverse_bn(BigNum a) {
    BigNum b;
    b.len = a.len;
    for (int i = 0; i < a.len; i++)
        b.d[i] = a.d[a.len - 1 - i];
    return b;
}

int is_palindrome(BigNum a) {
    for (int i = 0; i < a.len / 2; i++) {
        if (a.d[i] != a.d[a.len - 1 - i]) return 0;
    }
    return 1;
}

int main() {
    int count = 0;
    for (int n = 1; n < 10000; n++) {
        BigNum val = from_long(n);
        int lychrel = 1;
        for (int i = 0; i < 50; i++) {
            val = add(val, reverse_bn(val));
            if (is_palindrome(val)) {
                lychrel = 0;
                break;
            }
        }
        if (lychrel) count++;
    }
    printf("%d\n", count);
    return 0;
}
