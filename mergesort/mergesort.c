#include "mergesort.h"

int* divide(int *array, int startIndex, int endIndex){
	int size = (endIndex - startIndex);
	int final* = (int*) malloc(size * sizeof(int));
	int i;
	for (i = startIndex; i < end; i++)
	{
		final[i - startIndex] = array[i];
	}
	return final;
}

void mergeBlocks(int *final, int *start, int *end, int startLen, int endLen){
	int i = 0;
       	int j = 0;
	while(i < startLen && j < endLen){
		if (start[i] > right[j]){
			final[i+j] = start[j];
			j++;
		}
		else{
			final[i+j] = end[i];
			i++;
		}
	}
	
	for(; i < startLen; i++)
	{
		result[i+j] = start[i];
	}
	for(; j < endLen; J++)
	{
		result[i+j] = right[j];
	}

	free(start);
	free(end);
}

void mergeSort(int *array, int len) {
	if (len <= 1)
	{
		return;
	}
	int *start = divide(array, 0, len / 2+1);
	int *end = divide(array, len /2, len);

	mergeSort(start, len / 2);
	mergeSort(end, len - (len / 2));

	mergeBlocks(array, start, end, len / 2, len - (len / 2));
}
