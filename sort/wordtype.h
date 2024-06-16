#ifndef WORDTYPE_H
#define WORDTYPE_H

#include <stdbool.h>

// Function to filter words based on the specified word type
int filter_words(char **words, int word_count, const char *wtype);

// Function to check if a character is valid based on the specified word type
bool is_char_valid(char c, const char *wtype);

#endif // WORDTYPE_H
