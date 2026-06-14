#include <stdio.h>

int main() {
    double c[101][101] = {0};
    int count = 0;

    for (int n = 0; n <= 100; n++) {
        c[n][0] = 1;
        for (int r = 1; r <= n; r++) {
            c[n][r] = c[n-1][r-1] + c[n-1][r];
            if (c[n][r] > 1000000) {
                c[n][r] = 1000001;
                count++;
            }
        }
    }

    printf("%d\n", count);
    return 0;
}
