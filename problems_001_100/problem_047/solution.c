#include <stdio.h>
#include <stdlib.h>

#define LIMIT 1000000

int main() {
    int *omega = (int *)calloc(LIMIT, sizeof(int));
    if (!omega) return 1;

    for (int i = 2; i < LIMIT; i++) {
        if (omega[i] == 0) {
            for (int j = i; j < LIMIT; j += i) {
                omega[j]++;
            }
        }
    }

    int streak = 0;
    for (int i = 2; i < LIMIT; i++) {
        if (omega[i] == 4) {
            streak++;
            if (streak == 4) {
                printf("%d\n", i - 3);
                break;
            }
        } else {
            streak = 0;
        }
    }

    free(omega);
    return 0;
}