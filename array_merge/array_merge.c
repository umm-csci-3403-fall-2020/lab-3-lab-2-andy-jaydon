#include "array_merge.h"
#include <stdlib.h>
int* array_merge(int num_arrays, int* sizes, int** values) {
  
  if ((num_arrays = 0))
	  return 0;

  int sumSizes = 0;
  int i = 0;
  for (i = 0; i < num_arrays; i++)
	  sumSizes += sizes[i];

  int* arr = (int*) calloc(sumSizes + 1, sizeof(int));

  int j = 0;
  int l = 0;
  int m = 0;
  for (j = 0; j < num_arrays; j++)
	  for (l = 0; l < sizes[j]; l++){
		  arr[m] = values[j][l];
  		  m++;
	  }
  mergesort(sumSizes, arr);
  int n = 0;
  int o = 0;
  for (n = 0; n < sumSizes; n++){
	  for (o = n+1; o < sumSizes; o++){
		  if(arr[n] == arr[o]){
			  arr[o] = arr[o + 1];
			  sumSizes--;
			  o--;
		  }
	  }
  }
  return arr;
}
