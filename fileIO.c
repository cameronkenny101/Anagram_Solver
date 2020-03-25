//
// Created by camek on 08/02/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include "fileIO.h"

int readSentences(char inputSentences[][MAX_CHAR])
{
    int lineNum = 0; // Integer lineNum. This will increment each time a new sentence is stored in the array.
    int i, j;

    FILE *pointerToFile = fopen("C:\\Users\\camek\\CLionProjects\\Assignment1\\InputFiles\\input.txt", "r");

    if(pointerToFile == NULL) // If the pointer does not read in the file it returns an error message and exits the function.
    {
        perror("Error checking text file");
        exit(0);
    }
    else{
        while(fgets(inputSentences[lineNum], sizeof(inputSentences[lineNum]), pointerToFile) != NULL) /* Gets the sentence from file
        and stores in inputSentences array. */
        {
            lineNum++;
        }
        fclose(pointerToFile); // Closes the pointer to file.
    }
    for(i = 0; i < lineNum; i++)
    {
        for(j = 0; j < MAX_CHAR; j++)
        {
            if(inputSentences[i][j] == '\n') // Switches the new line to null terminator
            {
                inputSentences[i][j] = '\0';
                break; /* When it switches new line to null terminator it breaks. This saves time as it does not need to run through
                the rest of the array */
            }
        }
    }
    return lineNum; // returns the value in lineNum.



}

