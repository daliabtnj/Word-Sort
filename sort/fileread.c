#include "fileread.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a word is in the skip words list
bool is_skipword(char *word, char **skipwords) {
    if (skipwords == NULL) return false;
    for (int i = 0; skipwords[i] != NULL; i++) {
        if (strcmp(word, skipwords[i]) == 0) {
            return true; // It is a skipword
        }
    }
    return false; // Not a skip word
}

// Function to read the entire file content dynamically
char *read_file(FILE *fp) {
    fseek(fp, 0, SEEK_END); // Move to the end of the file
    long file_size = ftell(fp); // Get the file size
    fseek(fp, 0, SEEK_SET); // Move back to the beginning of the file

    char *buffer = malloc(file_size + 1); // Allocate buffer to hold the file content
    if (buffer) {
        fread(buffer, 1, file_size, fp); // Read the file content into the buffer
        buffer[file_size] = '\0'; // Null-terminate the buffer
    }
    return buffer;
}

// Function to read words from a file into an array
int file_words(const char *inputfile, char **words, char **skipwords) {
    FILE *fp = fopen(inputfile, "r");

    if (fp == NULL) {
        perror("Sorry, could not open file :(");
        exit(1);
    }

    char *buffer = read_file(fp); // Read the file
    fclose(fp);

    if (!buffer) {
        perror("Error with file reading :(");
        exit(1);
    }

    int c = 0; // Count words
    char *token = strtok(buffer, " \t\n\r,;\'\"()"); // Delimiters to store words

    while (token != NULL) {
        if (!is_skipword(token, skipwords)) { // Check if it's a skipword
            words[c] = strdup(token); // Store the word in the array
            c++;
        }
        token = strtok(NULL, " \t\n\r,;\'\"()"); // Get next token
    }

    free(buffer);
    return c;
}
