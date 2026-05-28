
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *x, char *y) {
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Function to find the next permutation
int next_permutation(char *str) {
    int len = strlen(str);
    int i = len - 2;
    while (i >= 0 && str[i] >= str[i + 1]) {
        i--;
    }
    if (i < 0) {
        return 0; // No more permutations
    }
    int j = len - 1;
    while (str[j] <= str[i]) {
        j--;
    }
    swap(&str[i], &str[j]);
    int left = i + 1;
    int right = len - 1;
    while (left < right) {
        swap(&str[left], &str[right]);
        left++;
        right--;
    }
    return 1;
}

int main() {
    char s[] = "0123456789";
    long long sum = 0;
    int primes[] = {2, 3, 5, 7, 11, 13, 17};
    
    do {
        int valid = 1;
        for (int i = 0; i < 7; ++i) {
            int num = (s[i+1] - '0') * 100 + (s[i+2] - '0') * 10 + (s[i+3] - '0');
            if (num % primes[i] != 0) {
                valid = 0;
                break;
            }
        }
        
        if (valid) {
            long long current_val = 0;
            for(int k=0; k<10; k++){
                current_val = current_val * 10 + (s[k] - '0');
            }
            sum += current_val;
        }
    } while (next_permutation(s));
    
    printf("%lld\n", sum);
    return 0;
}
