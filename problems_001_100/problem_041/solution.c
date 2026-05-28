
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

bool prev_permutation(char *str) {
    int len = strlen(str);
    int i = len - 2;
    while (i >= 0 && str[i] <= str[i+1]) {
        i--;
    }
    if (i < 0) return false;
    
    int j = len - 1;
    while (str[j] >= str[i]) {
        j--;
    }
    
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    
    int left = i + 1;
    int right = len - 1;
    while (left < right) {
        temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
    return true;
}

int main() {
    char digits[] = "7654321";
    do {
        int val = atoi(digits);
        if (is_prime(val)) {
            printf("%d\n", val);
            return 0;
        }
    } while (prev_permutation(digits));
    
    return 0;
}
