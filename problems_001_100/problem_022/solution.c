#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAMES 6000
#define MAX_NAME_LEN 50

// Comparison function needed for qsort to sort strings alphabetically
int compare_strings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    FILE *file = fopen("p022_names.txt", "r");
    if (!file) {
        printf("Error: Could not open p022_names.txt\n");
        return 1;
    }

    char *names[MAX_NAMES];
    int name_count = 0;
    char buffer[MAX_NAME_LEN];
    int char_idx = 0;
    int c;

    // Parse the file character by character
    while ((c = fgetc(file)) != EOF) {
        if (c == '"') {
            continue; // Ignore quotes
        } else if (c == ',') {
            buffer[char_idx] = '\0'; // Null-terminate the string
            names[name_count] = strdup(buffer); // Copy to our array
            name_count++;
            char_idx = 0; // Reset for the next name
        } else {
            buffer[char_idx++] = c;
        }
    }
    
    // Catch the very last name in the file
    if (char_idx > 0) {
        buffer[char_idx] = '\0';
        names[name_count++] = strdup(buffer);
    }
    fclose(file);

    // Sort the array of strings
    qsort(names, name_count, sizeof(char *), compare_strings);

    // Calculate the total score
    long long total_score = 0;
    for (int i = 0; i < name_count; i++) {
        int alpha_val = 0;
        for (int j = 0; names[i][j] != '\0'; j++) {
            alpha_val += names[i][j] - 'A' + 1; // ASCII math
        }
        total_score += (long long)alpha_val * (i + 1);
        free(names[i]); // Clean up memory
    }

    printf("Total of all name scores: %lld\n", total_score);
    return 0;
}