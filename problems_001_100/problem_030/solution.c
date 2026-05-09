#include <stdio.h>

int main() {
    int sum = 0;
    int p[10];
    for (int i = 0; i < 10; ++i) {
        p[i] = i * i * i * i * i;
    }
    for (int i = 10; i < 355000; ++i) {
        int temp = i;
        int s = 0;
        while (temp > 0) {
            s += p[temp % 10];
            temp /= 10;
        }
        if (s == i) {
            sum += i;
        }
    }
    printf("%d\n", sum);
    return 0;
}
