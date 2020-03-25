//
// Created by camek on 20/02/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include "outputText.h"


void writeSentences(char outputSentences[][MAX_CHAR], int lines)
{
    FILE *pointerToFile = fopen("C:\\Users\\camek\\CLionProjects\\Assignment1\\InputFiles\\output.txt", "w"); /* Sets up
    pointer to write into the file */

    if(pointerToFile == NULL)
    {
        perror("Error inputting to text file"); // If the pointer does not read in the file it returns an error message and exits the function.
        exit(0);
    } else
        {
        fprintf(pointerToFile, "The sorted string is : \n"); // Prints to file not terminal
            for(int i = 0; i < lines; i++)
            {
                fprintf(pointerToFile,"%s\n",outputSentences[i]); // Prints sorted string
            }
            fclose(pointerToFile); // Closes pointer to file
        }

}
void writeAnagrams(int outputAnagrams[5][5], int numOfAnagrams, char array[][MAX_CHAR])
{
    FILE *pointerToFile = fopen("C:\\Users\\camek\\CLionProjects\\Assignment1\\InputFiles\\output.txt", "a+"); // Appends the file
    if(pointerToFile == NULL)
    {
        perror("Error inputting to text file"); // If the pointer does not read in the file it returns an error message and exits the function.
        exit(0);
    } else
        {
        int count = 1;
        fprintf(pointerToFile, "\n"); // Print a newline to file
            for(int i = 0; i < numOfAnagrams; i++)
            {

                if(outputAnagrams[i][0] != outputAnagrams[i - 1][0] && outputAnagrams[i][0] != outputAnagrams[i-2][1]) // If not the same index we enter in here
                {
                    fprintf(pointerToFile, "\nAnagram Group %d: ", count); // Prints anagram group and number
                    count++; // Count increments
                }

                for(int j = 0; j < numOfAnagrams; j++)
                {
                    // If index on new line is the same we do not enter in here, else we do
                    if(outputAnagrams[i][j] >= 0 && outputAnagrams[i][j] != outputAnagrams[i-1][j] && outputAnagrams[i][j] != outputAnagrams[i-1][j] && outputAnagrams[i][j] != outputAnagrams[i-2][j+1])
                    {
                        fprintf(pointerToFile, " %s ", array[outputAnagrams[i][j]]); // Prints string
                    }
                }

            }
            fprintf(pointerToFile, "\n"); // Formatting purposes
        }


    fclose(pointerToFile); // Close pointer file
}
void writeMissingAnagrams(char array[][MAX_CHAR], int lengthOfStrings[MAX_LINES], int i, int j)
{
    FILE *pointerToFile = fopen("C:\\Users\\camek\\CLionProjects\\Assignment1\\InputFiles\\output.txt", "a+"); // Appends file
    if(pointerToFile == NULL)
    {
        perror("Error inputting to text file"); // If the pointer does not read in the file it returns an error message and exits the function.
        exit(0);
    }
    else
    {
        fprintf(pointerToFile, "\n%s is a missing anagram of %s if %d letters are removed", array[i], array[j], lengthOfStrings[i] - lengthOfStrings[j]);
        // Prints the strings that are arrays of each other and the amount of letters that must be removed fro the end of sentence to make it  proper anagram
    }

    fclose(pointerToFile); // Closes pointer to file
}
