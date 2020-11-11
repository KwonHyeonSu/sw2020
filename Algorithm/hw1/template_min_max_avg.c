/* 2016115572 ±ÇÇö¼ö  2020000319 Algorithm One
 * COMP319 Algorithms, Spring 2020
 * Find max, min, and average of an array from a file
 */

// DIRECTIONS:
// complete the functions Maximum, Minimum, and Average by filling out
// /* FILL */ parts
// see the descriptions below the function names

#include <stdio.h>
#include <stdlib.h>

short Maximum( short A[], int num, int *imax )
  // INPUT: short array, number of array elemement by int
  //    imax is a pointer to an integer
  // returns the maximum value of the array
  // the localtion of the maximum value is stored to *imax
  // if the array is empty, set *imax = -1 and returns -100
{
  int i;
  short max;

  if ( num <= 0 ) { *imax = -1; return -100; }	// no element
  else {
  	
  	max = A[0];
	for(i=0;i<num;i++){
	  	if(A[i]>max){
	  		max = A[i];
	  		*imax = i;
		  }
	  } 
  	return max;
  }
}

short Minimum( short A[], int num, int *imin )
  // returns the minimum value of the array
  // the localtion of the minimum value is stored to *imin
  // if the array is empty, set *imin = -1 and returns -100
{
	int i;
	short min;
	
	if(num <= 0) {
		*imin = -1;
		return -100;
	}else{
		min = A[0];
		for(i=0;i<num;i++){
			if(A[i]<min){
				min = A[i];
				*imin = i;
			}
			
		}
		return min;
		
	}
}

double Average( short A[], int num )
  // returns the average of the values in the array
  // if the array is empty, returns -100.0
{
  int i;
  double sum;

  if ( num <= 0 ) return -100.0;	// no element
  else {
  	for(i=0;i<num;i++) sum += A[i];
  	return sum/num;
  }
}

int main()
{
  short *A, tmp;
  int imax, imin;
  short min, max;
  double avg;
  int numElements;
  int i;
  FILE *fp;

  /* for file name, max length 1023 including path */
  char filename[1024];

  /* file name given by keyboard */
  printf("File name? ");
  scanf("%s",filename);

  // check for file 
  fp = fopen(filename,"r");
  if ( !fp ) {
    fprintf(stderr, "cannot open file %s\n",filename);
    return -1;
  }
  else {
    // check for number of elements
    if ( fscanf(fp, "%d", &numElements) != 1 || numElements < 0 ) {
      fprintf(stderr, "cannot read number of elements %s\n",filename);
      return -1;
    }
    else {
      // allocate memory if necessary
      if ( numElements > 0 ) A = (short*)malloc(sizeof(short)*numElements);
      else A = NULL; 

      for (i=0; i<numElements; i++) {
		if ( fscanf(fp, "%hd", &tmp) != 1 ) {
		  fprintf(stderr, "cannot read value at %d/%d\n",i+1,numElements);
		  return -1;
		}
		else A[i] = tmp;
      }
      printf("A = [");
      for (i=0; i<numElements; i++) printf("%d ",A[i]);
      printf("]\n");

      printf("==========================================\n");

      // find the minimum 
      min = Minimum(A, numElements, &imin);
      printf("minimum = %hd, at %d\n",min, imin);

      // find the maximum 
      max = Maximum(A, numElements, &imax);
      printf("maximum = %hd, at %d\n",max, imax);

      // find the average 
      avg = Average(A, numElements);
      printf("Average = %.2f\n",avg);

      // once allocated, should be freed after use
      if ( A ) free(A);
    }
    // once opened, should be closed after use
    fclose(fp);
  }

  return 0;
}
