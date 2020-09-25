#ifndef MERGESORT_H_GUARD
#define MERGESORT_H_GUARD

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define LENGTH 100
#define UNIT_TESTING

int * divide(int *array, int startIndex, int endIndex);
void mergeBlocks(int *final, int *start, int end*, int startLen, int endLen);
void printArray(int array*, int len);
void mergesort(int *array, int len);

#endif
