cmake_minimum_required(VERSION 3.15)
project(Assignment1 C)

set(CMAKE_C_STANDARD 11)

add_executable(Assignment1 main.c fileIO.h fileIO.c quicksortFile.h quicksortFile.c sizes.h lowerCase.h lowerCase.c outputText.c outputText.h anagrams.c anagrams.h missingAnagrams.c missingAnagrams.h)