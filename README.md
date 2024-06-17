### Word Sorter

A simple C program to read words from a file, filter them based on word type, sort them, and display the result.

#### Features
- Read words from a file into an array of strings, 
- Filter words based on word type (alphabetical, alphanumeric, or all characters)
- Ignore characters of invalid word type and stores only valid characters from the word
- Sort words in ascending or descending order
- Display sorted words with specified formatting

#### Usage
./ssort.exe <inputfile> <n> <wtype> <sorttype> [<skipword1> <skipword2> <skipword3> ...]
- `<inputfile>`: Path to the input file, if not specified, the program displays an error message and terminates.
- `<n>`: Number of words to read from the file.
- `<wtype>`: Word type specifier (ALPHA, ALPHANUM, ALL).
- `<sorttype>` (Optional): Sorting order ASC or DESC (ASC by default).
- `<skipword>` (Optional): Words to skip during processing.

## Example
./ssort.exe input.txt 100 ALPHA ASC the and a

## Evaluation
The code will be tested on a standard Linux environment.



