//
// Created by camek on 20/02/2020.
//
#include "sizes.h"

#ifndef ASSIGNMENT1_OUTPUTTEXT_H
#define ASSIGNMENT1_OUTPUTTEXT_H

void writeSentences(char outputSentences[MAX_LINES][MAX_CHAR], int lines);
void writeAnagrams(int outputAnagrams[5][5], int numOfAnagrams, char array[][MAX_CHAR]);
void writeMissingAnagrams(char array[][MAX_CHAR], int lengthOfStrings[MAX_LINES], int i, int j);

#endif //ASSIGNMENT1_OUTPUTTEXT_H
