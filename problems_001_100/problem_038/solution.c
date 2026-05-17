/*
 * Project Euler - Problem 038
 * Pandigital Multiples
 * https://projecteuler.net/problem=38
 *
 * Author: 0x4r35
 * Language: C
 *
 * What is the largest 1 to 9 pandigital 9-digit number that can be
 * formed as the concatenated product of an integer with (1, 2, ..., n)
 * where n > 1?
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* Check if a 9-character string is 1-to-9 pandigital */
bool is_pandigital(const char *s) {
    if (strlen(s) != 9) return false;

    int digits[10] = {0};
    for (int i = 0; i < 9; i++) {
        int d = s[i] - '0';
        if (d == 0 || digits[d]) return false;
        digits[d] = 1;
    }
    return true;
}

int main() {
    int largest = 0;

    /*
     * We need n > 1, so the integer must produce at least 2 products.
     * For n=2: integer * 1 concatenated with integer * 2 = 9 digits.
     * A 4-digit number * (1,2) gives 4+5 = 9 digits (possible).
     * So we check integers up to 9999.
     */
    for (int i = 1; i <= 9999; i++) {
        char concat[20] = "";
        int len = 0;

        for (int n = 1; len < 9; n++) {
            char buf[10];
            int written = sprintf(buf, "%d", i * n);
            strcat(concat, buf);
            len += written;
        }

        if (len == 9 && is_pandigital(concat)) {
            int value = atoi(concat);
            if (value > largest)
                largest = value;
        }
    }

    printf("%d\n", largest);
    return 0;
}
