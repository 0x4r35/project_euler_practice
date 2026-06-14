#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define LIMIT 1000000

bool sieve[LIMIT];
int digits[7];
int num_digits;

void init_sieve() {
    for (int i = 2; i < LIMIT; i++) sieve[i] = true;
    for (int p = 2; p * p < LIMIT; p++) {
        if (sieve[p]) {
            for (int i = p * p; i < LIMIT; i += p)
                sieve[i] = false;
        }
    }
}

void get_digits(int n) {
    num_digits = 0;
    int tmp = n;
    while (tmp > 0) {
        digits[num_digits++] = tmp % 10;
        tmp /= 10;
    }
}

int main() {
    init_sieve();

    for (int n = 56003; n < LIMIT; n++) {
        if (!sieve[n]) continue;
        get_digits(n);

        for (int mask = 1; mask < (1 << num_digits); mask++) {
            int positions[7], pos_count = 0;
            for (int b = 0; b < num_digits; b++) {
                if (mask & (1 << b))
                    positions[pos_count++] = b;
            }

            bool all_same = true;
            for (int p = 1; p < pos_count; p++) {
                if (digits[positions[p]] != digits[positions[0]]) {
                    all_same = false;
                    break;
                }
            }
            if (!all_same) continue;

            int family_count = 0;
            int smallest = 0;

            for (int d = 0; d <= 9; d++) {
                int val = 0, mult = 1;
                for (int b = num_digits - 1; b >= 0; b--) {
                    int dig;
                    bool replaced = false;
                    for (int p = 0; p < pos_count; p++) {
                        if (positions[p] == b) {
                            replaced = true;
                            break;
                        }
                    }
                    dig = replaced ? d : digits[b];
                    val = val * 10 + dig;
                }

                if (val < mult) continue;
                int check_digits = 0;
                int tmp = val;
                while (tmp > 0) { check_digits++; tmp /= 10; }
                if (check_digits != num_digits) continue;

                if (val >= 2 && val < LIMIT && sieve[val]) {
                    if (family_count == 0) smallest = val;
                    family_count++;
                }
            }

            if (family_count >= 8 && smallest == n) {
                printf("%d\n", n);
                return 0;
            }
        }
    }

    return 0;
}
