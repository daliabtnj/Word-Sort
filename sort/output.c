#include "output.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparison function for ascending order
int compare_asc(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

// Comparison function for descending order
int compare_desc(const void *a, const void *b) {
    return strcmp(*(const char **)b, *(const char **)a);
}

// Function to sort words based on the specified sort type
void sort_words(char **words, int word_count, const char *sorttype) {
    if (strcmp(sorttype, "DESC") == 0) {
        qsort(words, word_count, sizeof(char *), compare_desc);
    } else {
        qsort(words, word_count, sizeof(char *), compare_asc);
    }
}

// Function to print words with specified formatting
void print_words(char **words, int word_count, int n) {
    int count = 0;
    printf ("\n");
    printf("*******************************\n");
    for (int i = 0; i < n && i < word_count; i++) {
        if (count > 0 && count % 10 == 0) {
            printf("\n");
        }
        if (count > 0 && count % 10 != 0) {
            printf(" ");
        }
        printf("%s", words[i]);
        count++;
    }
    printf("\n*******************************");
    printf("\n");
}
