#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define LIMIT 10000
#define MAX_PRIMES 1300

int primes[MAX_PRIMES];
int prime_count = 0;
int trial_primes[MAX_PRIMES];
int trial_count = 0;
signed char *compat;
int chosen[5];
int best_sum = INT_MAX;

void build_primes() {
    int is_prime[LIMIT + 1];
    for (int i = 0; i <= LIMIT; i++) is_prime[i] = 1;
    is_prime[0] = is_prime[1] = 0;

    for (int p = 2; p * p <= LIMIT; p++) {
        if (is_prime[p]) {
            for (int m = p * p; m <= LIMIT; m += p) {
                is_prime[m] = 0;
            }
        }
    }

    for (int i = 2; i <= LIMIT; i++) {
        if (is_prime[i]) {
            trial_primes[trial_count++] = i;
            if (i != 2 && i != 5) {
                primes[prime_count++] = i;
            }
        }
    }
}

long long concat(int a, int b) {
    int pow10 = 10;
    while (pow10 <= b) {
        pow10 *= 10;
    }
    return (long long)a * pow10 + b;
}

int is_prime_long(long long n) {
    if (n < 2) return 0;
    for (int i = 0; i < trial_count && (long long)trial_primes[i] * trial_primes[i] <= n; i++) {
        if (n % trial_primes[i] == 0) {
            return n == trial_primes[i];
        }
    }
    return 1;
}

int compatible(int i, int j) {
    int a = i < j ? i : j;
    int b = i < j ? j : i;
    int idx = a * prime_count + b;

    if (compat[idx] == -1) {
        int ok = is_prime_long(concat(primes[a], primes[b])) &&
                 is_prime_long(concat(primes[b], primes[a]));
        compat[idx] = (signed char)ok;
    }

    return compat[idx] == 1;
}

void search(int start, int depth, int sum) {
    if (depth == 5) {
        if (sum < best_sum) {
            best_sum = sum;
        }
        return;
    }

    for (int i = start; i < prime_count; i++) {
        if (sum + primes[i] * (5 - depth) >= best_sum) {
            break;
        }

        int ok = 1;
        for (int j = 0; j < depth; j++) {
            if (!compatible(chosen[j], i)) {
                ok = 0;
                break;
            }
        }
        if (!ok) continue;

        chosen[depth] = i;
        search(i + 1, depth + 1, sum + primes[i]);
    }
}

int main() {
    build_primes();

    compat = (signed char *)malloc((size_t)prime_count * prime_count);
    if (!compat) return 1;
    for (int i = 0; i < prime_count * prime_count; i++) {
        compat[i] = -1;
    }

    search(0, 0, 0);
    printf("%d\n", best_sum);

    free(compat);
    return 0;
}
