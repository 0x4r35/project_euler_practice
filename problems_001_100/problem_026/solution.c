#include <stdio.h>

int main() {
    int max_length = 0;
    int best_d = 0;
    
    for (int d = 2; d < 1000; d++) {
        int remainders[1005] = {0};
        int value = 1;
        int position = 1;
        
        while (remainders[value] == 0 && value != 0) {
            remainders[value] = position;
            value *= 10;
            value %= d;
            position++;
        }
        
        if (value != 0) {
            int cycle_length = position - remainders[value];
            if (cycle_length > max_length) {
                max_length = cycle_length;
                best_d = d;
            }
        }
    }
    
    printf("The value of d < 1000 for which 1/d contains the longest recurring cycle is: %d\n", best_d);
    return 0;
}
