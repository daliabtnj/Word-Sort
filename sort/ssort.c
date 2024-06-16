#include "fileread.h"
#include "wordtype.h"
#include "output.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ssort.exe <inputfile> <n> <wtype> <sorttype> [<skipword1> <skipword2>..]
int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Error, input is invalid!\n");
        fprintf(stderr, "Please enter in this format: ssort.exe <inputfile> <n> <wtype> <sorttype> [<skipword1> <skipword2>..]");
        return 1;
    }

    const char *fp = argv[1];
    const int n = atoi(argv[2]);
    const char *wtype = argv[3];
    const char *sorttype = "ASC"; // default value for sorttype

    int skipwords_index = 4;

    // Check if there is a sorttype
    if (argc > 4 && (strcmp(argv[4], "ASC") == 0 || strcmp(argv[4], "DESC") == 0)) {
        sorttype = argv[4];
        skipwords_index = 5;
    }

    if (n <= 0) {
        fprintf(stderr, "Error, please enter a positive integer n.");
        return 1;
    }

    char **skipwords = NULL;
    if (argc > skipwords_index) {
        int total_skipwords = argc - skipwords_index;
        skipwords = malloc((total_skipwords + 1) * sizeof(char *));
        for (int i = 0; i < total_skipwords; i++) {
            skipwords[i] = argv[skipwords_index + i];
        }
        skipwords[total_skipwords] = NULL;
    }

    char **words = malloc(n * sizeof(char *));
    int word_count = file_words(fp, words, skipwords);

    // Filter words based on word type
    int filtered_count = filter_words(words, word_count, wtype);

    // Sort words
    sort_words(words, filtered_count, sorttype);

    // Print words
    print_words(words, filtered_count, n);

    for (int i = 0; i < filtered_count; i++) {
        free(words[i]);
    }
    free(words);
    if (skipwords) {
        free(skipwords);
    }

    return 0;
}

