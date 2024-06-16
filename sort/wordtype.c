#include "wordtype.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a character is valid based on the specified word type
bool is_char_valid(char c, const char *wtype) {
    if (strcmp(wtype, "ALPHA") == 0) {
        return isalpha(c);
    } else if (strcmp(wtype, "ALPHANUM") == 0) {
        return isalnum(c);
    } else if (strcmp(wtype, "ALL") == 0) {
        return c != ' ' && c != '\t' && c != '\n' && c != '\r' && c != ',' && c != '_' && c != ';' && c != '\'' && c != '(' && c != ')' && c !='.';
    } else {
        return false; // Invalid word type
    }
}

// Function to filter words based on the specified word type
int filter_words(char **words, int word_count, const char *wtype) {
    int new_count = 0;
    for (int i = 0; i < word_count; i++) {
        int len = strlen(words[i]);
        char filtered_word[100]; // Temporary buffer to hold the filtered word
        int word_index = 0;

        for (int j = 0; j < len; j++) {
            if (is_char_valid(words[i][j], wtype)) {
                filtered_word[word_index++] = words[i][j];
            } else {
                break; // Stop at the first invalid character
            }
        }

        // Ensure the filtered word is null-terminated
        if (word_index > 0) {
            filtered_word[word_index] = '\0';
            free(words[i]); // Free the original word
            words[i] = strdup(filtered_word); // Duplicate the filtered word and store it back in the array
            new_count++;
        } else {
            free(words[i]); // Free the original word
            words[i] = NULL;
        }
    }

    // Remove NULL entries in the words array
    int final_count = 0;
    for (int i = 0; i < word_count; i++) {
        if (words[i] != NULL) {
            words[final_count++] = words[i];
        }
    }

    return final_count;
}
