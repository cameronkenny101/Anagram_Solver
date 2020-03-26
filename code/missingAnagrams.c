//
// Created by camek on 25/02/2020.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "missingAnagrams.h"
#include "anagrams.h"
#include "lowerCase.h"
#include "outputText.h"

void missingAnagrams(char array[][MAX_CHAR], int lines)
{
    int lengthOfStrings[lines]; // length of strings array is created again
    stringLength(lengthOfStrings, lines, array); // store the length of each string in the integer array lenghtOfStrings
    char copyI[MAX_CHAR]; // Create a copy string
    char copyJ[MAX_CHAR]; // Create a copy string

    for(int i = 0; i < lines; i++)
    {
        for (int j = 0; j < lines; j++)
        {
            if (lengthOfStrings[i] > lengthOfStrings[j]) // If the length of one string is greater than another we enter in the if statement
            {
                copyLetters(copyI, array[i], lengthOfStrings[j]); /* pass in string, array index and the length of the smaller string. This function places a null
                terminator in the string array[i] after the number in lengthOfStrings[j] has been counted through the string array. This effectively
                cuts the array to be the size of the smaller array */

                toLowerCase(copyI); // Makes the new cut string lowercase
                strcpy(copyJ, array[j]); // copies the string that was smaller into the the copied replica string
                toLowerCase(copyJ); // Makes copied string lowercase

                bool anagram = checkAnagram(copyI, copyJ); // Returns a true or false value into the boolean anagram.
                if (anagram) {
                    writeMissingAnagrams(array, lengthOfStrings, i, j); /* If its an anagram we print the index of the array that
                    are missing anagrams. Pass in the length of strings array so we can take away the two indexes so we know
                    how many characters removed will make it an anagram. */
                }

            }
        }
    }
}

void copyLetters(char copiedString[MAX_CHAR], char originalString[MAX_CHAR], int count)
{
    int letterCounter = 0;
    strcpy(copiedString, originalString);
    int i = 0;
    for(i = 0; letterCounter < count; i++)
    {
        if(isalpha(originalString[i]))
        {
            letterCounter++;
        }
    }
    copiedString[i] = '\0';
}