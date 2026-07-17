#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODES 2000

int load_codes(int codes[]) {
    const char *paths[] = {
        "p059_cipher.txt",
        "problems_001_100/problem_059/p059_cipher.txt"
    };
    FILE *file = NULL;

    for (int i = 0; i < 2 && file == NULL; i++) {
        file = fopen(paths[i], "r");
    }
    if (!file) {
        fprintf(stderr, "Cannot open p059_cipher.txt\n");
        return -1;
    }

    int count = 0;
    while (count < MAX_CODES && fscanf(file, "%d", &codes[count]) == 1) {
        count++;
        int ch = fgetc(file);
        if (ch == EOF) break;
    }

    fclose(file);
    return count;
}

int is_allowed_plaintext(int ch) {
    return ch == '\n' || (ch >= 32 && ch <= 126);
}

int count_word(const char *text, const char *word) {
    int count = 0;
    const char *pos = text;
    while ((pos = strstr(pos, word)) != NULL) {
        count++;
        pos++;
    }
    return count;
}

int score_text(const char *text, int len) {
    int score = 0;
    for (int i = 0; i < len; i++) {
        char c = (char)tolower((unsigned char)text[i]);
        if (c == ' ') score += 6;
        else if (strchr("etaoinshrdlu", c)) score += 3;
        else if (c >= 'a' && c <= 'z') score += 1;
    }

    score += 40 * count_word(text, " the ");
    score += 25 * count_word(text, " and ");
    score += 20 * count_word(text, " of ");
    score += 20 * count_word(text, " to ");
    score += 15 * count_word(text, " in ");
    return score;
}

int main() {
    int codes[MAX_CODES];
    int count = load_codes(codes);
    if (count < 0) return 1;

    int best_score = -1;
    int best_sum = 0;
    char best_text[MAX_CODES + 1];

    for (char a = 'a'; a <= 'z'; a++) {
        for (char b = 'a'; b <= 'z'; b++) {
            for (char c = 'a'; c <= 'z'; c++) {
                char key[3] = {a, b, c};
                char text[MAX_CODES + 1];
                int sum = 0;
                int valid = 1;

                for (int i = 0; i < count; i++) {
                    int plain = codes[i] ^ key[i % 3];
                    if (!is_allowed_plaintext(plain)) {
                        valid = 0;
                        break;
                    }
                    text[i] = (char)plain;
                    sum += plain;
                }
                if (!valid) continue;

                text[count] = '\0';
                int score = score_text(text, count);
                if (score > best_score) {
                    best_score = score;
                    best_sum = sum;
                    strcpy(best_text, text);
                }
            }
        }
    }

    (void)best_text;
    printf("%d\n", best_sum);
    return 0;
}
