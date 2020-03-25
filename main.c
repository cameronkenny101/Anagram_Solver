#include <stdio.h>
#include "fileIO.h"
#include "quicksortFile.h"
#include "lowerCase.h"
#include "outputText.h"
#include "anagrams.h"
#include <string.h>
#include "missingAnagrams.h"

int main()
{
    char sentences[MAX_LINES][MAX_CHAR]; // Declared 2D array of size 20 rows and 60 columns

    int lines = readSentences(sentences); /* Let lines equal to what readSentences return. Lines is the number of sentences. This function
    reads in the input file and stores sentences in the 2d array called sentences */

    quickSort(sentences, 0, lines-1); /* Calling on quickSort and passing in array of sentences, the 0th index
    and the number of lines - 1th index */

    writeSentences(sentences, lines); // Function to write the sorted sentences to the Output file.

    anagrams(sentences, lines); /* Function that calls on multiple other functions while inside. It finds the anagrams and
    then prints out the anagrams to the output file */

    missingAnagrams(sentences, lines);  /* Function that passes in the array, looks for missing anagrams and then prints
    out the missing anagrams to the output file. */

}

