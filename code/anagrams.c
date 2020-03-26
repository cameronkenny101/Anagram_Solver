//
// Created by camek on 20/02/2020.
//
#include "anagrams.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "lowerCase.h"
#include "outputText.h"

void anagrams(char array[][MAX_CHAR], int numOfLines)
{
    int lengthOfStrings[numOfLines]; // Create an array to store the length of each string in
    int indexAnagram[ANAGRAM_SIZE][ANAGRAM_SIZE]; // 2d array to store the indexes of anagrams
    int numOfAnagrams = 0; // Initially numOfAnagrams is 0
    for(int i = 0; i < ANAGRAM_SIZE; i++) // Initialize a 2d array to store the indexes of each anagram
    {
        for(int j = 0; j < ANAGRAM_SIZE; j++)
        {
            indexAnagram[i][j] = -ANAGRAM_SIZE + i; /* Initialise the anagram to negative number so we can create an if stement that will allow us
            to only print the numbers greater than or equal to 0 */
        }
    }
    stringLength(lengthOfStrings, numOfLines, array); /* Get the string lengths of every string in one go and store it in the lenght of
    strings array we already initialised above */

    int h = 0;
    int k = 0;
    for(int i = 0; i < numOfLines; i++)
    {
        for(int j = i+1; j < numOfLines; j++)
        {
            if(lengthOfStrings[i] == lengthOfStrings[j]) // Run through our lengthOfStrings array and if any are equal we enter into this if statement
            {
                bool anagram = checkAnagram(array[i], array[j]); /* We pass in the indexes of i and j in the sentences array into check anagram function. We get
                a boolean value back from the function and let it equal to the boolean variable anagram */

                if(anagram) // If anagram is true we enter the if statement
                {
                    numOfAnagrams++; // Number of anagrams present increments
                    indexAnagram[h][k] = i; // The value in location (h, k) is now let equal to i which represents the first anagram
                    k++; // K increments
                    indexAnagram[h][k] = j; // The value in location (h, k) is now let equal to j which represents the second anagram
                    k = 0; // K is again set to 0
                    h++; // h is incremented
                }
            }
        }
    }

    writeAnagrams(indexAnagram, numOfAnagrams, array); /* After finding the anagrams I pass in the array, the 2d array of indexes of anagrams
    and the number of anagrams */

}
bool checkAnagram(char sentence1[MAX_CHAR], char sentence2[MAX_CHAR])
{
    int freq1[26]; // Create a frequency array
    int freq2[26]; // Create a frequency array
    frequencyLine(sentence1, freq1); // Pass in the first sentence into the first frequency array
    frequencyLine(sentence2, freq2); // Pass in the second sentence into the second frequency array
    bool anagram = true; // anagram is initialised to be true

    for(int i = 0; i < ALPHABET; i++) // run through each index in the array which has 26 indexes
    {
        if(freq1[i] != freq2[i]) // If they do not have the same number in the same index then an anagram is not present so anagram is set to false
        {
            anagram = false;
        }
    }
    return anagram; // return the truth value in anagram
}

void stringLength(int lengthOfStrings[MAX_LINES], int numOfLines, char array[][MAX_CHAR])
{
    char lowerCase[MAX_CHAR]; // lowerCase string array
    int count = 0; // count is set to 0

    for(int i = 0; i < numOfLines; i++)
    {
        count = 0; // count return back to 0 each time the 2nd loop is completed and the ith term in the first loop increments
        strcpy(lowerCase, array[i]); // copies string in array[i] into lowerCase
        toLowerCase(lowerCase); // makes lowerCase string lowercase
        for(int j = 0; j < strlen(array[i]); j++)
        {
            if(lowerCase[j] >= 'a' && lowerCase[j] <= 'z') // Goes through string and only of it is a letter then count will increment
            {
                count++;
            }
        }
        lengthOfStrings[i] = count; // length of strings array is let equal to the int count until the first loop finishes

    }
}

void frequencyLine(char sentence[MAX_CHAR], int freq[ALPHABET])
{
   char temp[MAX_CHAR]; // create temp string
   strcpy(temp, sentence); // Copies sentence passed in into temp
   toLowerCase(temp); // Turns temp string into lowercase

   for (int i = 0; i < ALPHABET; i++) {
       freq[i] = 0; // initialise frequency array
   }

   for(int i = 0; sentence[i] != '\0'; i++)
   {
       if(isalpha(sentence[i])) //isalpha checks if its a letter
       {
           freq[temp[i] - 'a']++; // Takes the letter away from the ascii code of a and then increments that index by 1
       }
   }
}