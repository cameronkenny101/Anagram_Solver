//
// Created by camek on 20/02/2020.
//

#ifndef ASSIGNMENT1_ANAGRAMS_H
#define ASSIGNMENT1_ANAGRAMS_H

#include "sizes.h"
#include <stdbool.h>

void anagrams(char array[][MAX_CHAR], int numOfLines);
bool checkAnagram(char sentence1[MAX_CHAR], char sentence2[MAX_CHAR]);
void stringLength(int lengthOfStrings[MAX_LINES], int numOfLines, char array[][MAX_CHAR]);
void frequencyLine(char sentence[MAX_CHAR], int freq[ALPHABET]);


#endif //ASSIGNMENT1_ANAGRAMS_H
