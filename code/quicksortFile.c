//
// Created by camek on 10/02/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quicksortFile.h"
#include "sizes.h"
#include "lowerCase.h"

void swap(char array[][MAX_CHAR], int i, int j) {
    char temp[60]; // Create a new temporary 1d string array.
    strcpy(temp, array[j]); // Copies the string index of array j into temp.
    strcpy(array[j], array[i]); // Copies the string index of array i into array j.
    strcpy(array[i], temp); // Copies the temp string into array i.
}


int partition(char array[][MAX_CHAR], int first, int last) {

    swap(array, first, (first + last) / 2); // swaps first string in array with the middle string in array.

    int index1 = first + 1; // index is equal to number of first index + 1
    int index2 = last; // index is equal to number of last

    char lowerPivot[MAX_CHAR]; // Creates a string array
    strcpy(lowerPivot, array[first]); // Copies string in index of first in array to lowerPivot string array
    toLowerCase(lowerPivot); // lowerPivot is now put in the function toLowerCase and is made to be all lowercase
    char lowerIndex2[MAX_CHAR]; /* Having a lowerIndex version of array[index] allows us to create a replica of the array index string,
    make it lowercase and use that to compare the strings so that quickSort ignores the capital letter but does not have to make everything
    in the array lowercase */

    char lowerIndex1[MAX_CHAR]; // The other string placeholder that is made lowercase


    while (index1 <= index2) // While loop runs as long as index1 is not bigger than index2
    {
        strcpy(lowerIndex1, array[index1]); /* Copy string to ignore capital letters. Copies string in while loop as the string lowerIndex1,
        must be different each time the while loop runs */

        toLowerCase(lowerIndex1); // Turns string lowercase
        strcpy(lowerIndex2, array[index2]); // Repeats above step with index2
        toLowerCase(lowerIndex2); // Again turns string lowercase

        if (strcmp(lowerIndex1, lowerPivot) < 0)  // if lowerIndex1 is alphabetically less than lowerPivot, we enter this if statement
        {
            index1++; // incremented
        }

        else if (strcmp(lowerIndex2, lowerPivot) > 0) // if lowerIndex2 is alphabetically greater than lowerPivot we enter this if statement
        {
            index2--; // decremented
        }
        else // if neither than we enter in here
        {
            swap(array, index1, index2); // swaps the elements in the array using the swap function
            index1++; // after swapping index1 is incremented
            index2--; // after swapping index2 it is decremented
        }
    }
    swap(array, first, index2); // After the while loop we swap the first index with index2 which is the last index
    return index2; // We then return the value in index2
}

void quickSort(char array[][MAX_CHAR], int first, int last) {
    if (first < last) // enter as long as first is less than last.
    {
        int pivotIndex = partition(array, first, last); // pivotIndex is equal to index2
        quickSort(array, first, pivotIndex - 1); // quickSort the bottom half of the array
        quickSort(array, pivotIndex + 1, last); /* quickSorts the top half of the array. In this way we are dividing and conquering the array
        to make it alphabetically correct. We split it up in two and base it around our pivot. As the function calls on itself it sorts it recursively. */


    }
}





