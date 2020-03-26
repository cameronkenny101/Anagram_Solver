//
// Created by camek on 12/02/2020.
//
#include "lowerCase.h"
#include "ctype.h"
#include <stdio.h>

void toLowerCase(char sentence[MAX_CHAR])
{
    int i;
    for(i = 0; sentence[i] != '\0'; i++) // runs until null terminator is present
    {
        sentence[i] = (char) tolower((int)sentence[i]); // casts the char to an ascii value and uses tolower function to make lowercase.
    }
}
