#include "array_merge.h"
#include "../mergesort/mergesort.c"
#include "../mergesort/mergesort.h"
#include <stdlib.h>
#include <stdio.h>

int* array_merge(int num_arrays, int* sizes, int** values) {
//Check for no arrays and return zero
//  if ((num_arrays = 0))
//	  return 0;
//Initialize variable for finding sum of sizes
  int sumSizes = 0;

  for (int i = 0; i < num_arrays; i++)
	  sumSizes = sumSizes + sizes[i];
//Allocate memory to array to hold values
  int* AnArr = (int*) calloc(sumSizes, sizeof(int));
//Store values in values inside new array
  int m = 0;
  for (int j = 0; j < num_arrays; j++)
	  for (int l = 0; l < sizes[j]; l++){
		  AnArr[m] = values[j][l];
  		  m++;
	  }
//Run mergesort on created array
  mergesort(sumSizes, AnArr);
//Total duplicats in array
  int dupNums = 0;
  for (int n = 0; n < sumSizes - 1; n++){
		  if(AnArr[n] == AnArr[n + 1]){
			  dupNums++;
		  }
  }

  int uniqueNums = sumSizes - dupNums;
//Create final array
  int* resultArr = (int*) calloc(uniqueNums+1, sizeof(int));
//Set first array value to the amount of unique characters
  resultArr[0] = uniqueNums;
//Needed line because single value test isn't stored properly 
  resultArr[1] = AnArr[0];
//Store unique values in new array
  int p = 2;
  for(int o = 1; o < sumSizes; o++) {
	if(AnArr[o] != AnArr[o-1]){
		resultArr[p] = AnArr[o];
		p++;
	}
  }
  free(AnArr);
  return resultArr;
}
