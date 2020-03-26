cmake_minimum_required(VERSION 3.15)
project(Assignment1 C)

set(CMAKE_C_STANDARD 11)

add_executable(Assignment1 code/main.c code/fileIO.h code/fileIO.c code/quicksortFile.h code/quicksortFile.c code/sizes.h code/lowerCase.h code/lowerCase.c code/outputText.c code/outputText.h code/anagrams.c code/anagrams.h code/missingAnagrams.c code/missingAnagrams.h)