/* ID: 2016115572 COMP319004
 * Name: 2016115572 Kwon Hyeon Su ±ÇÇö¼ö Algorithms
 * School of Electronics Engineering, Kyungpook National University
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	// string library

#define MAX_STR_LEN	256

/////////////////////////////////////////////////////////////
// print char array array
/////////////////////////////////////////////////////////////
void print_chararr_array( FILE *fp, char *A[], int N )
  // A[]: char string array to print
  // N:   size of the array
  // fp:  file pointer, stdout or stderr for screen display
{
  int i;
  fprintf(fp,"%d\n",N);
  for (i=0; i<N; i++) fprintf(fp,"%s ",A[i]);
  fprintf(fp,"\n");
}

/////////////////////////////////////////////////////////////
// read words from a text file
/////////////////////////////////////////////////////////////
char** read_chararr_textfile( const char infile[], int *pN )
  // returns an array of words, with its size stored in
  // the memory indicated by integer pointer variable pN
  // the retured memory should freed by the caller
{
  char **A;
  char tmp[MAX_STR_LEN];
  int i;
  FILE *fp;

  // check for input file name
  if ( infile == NULL ) {
    fprintf(stderr, "NULL file name\n");
    return NULL;
  }

  // check for file existence
  fp = fopen(infile,"r");
  if ( !fp ) {
    fprintf(stderr, "cannot open file %s\n",infile);
    return NULL;
  }
  else {
    // check for number of elements
    if ( fscanf(fp, "%d", pN) != 1 || *pN <= 0 ) {
      fprintf(stderr, "cannot read number of elements %s\n",infile);
      return NULL;
    }
    else {
      A = (char**)malloc(sizeof(char*)*(*pN));
      for (i=0; i<(*pN); i++) {
	if ( fscanf(fp, "%s", tmp) != 1 ) {
	  fprintf(stderr, "cannot read value at %d/%d\n",i+1,(*pN));
	  *pN = i;	// read data items
	  return A;
	}
	else {
	  A[i] = (char*) malloc(sizeof(char)*MAX_STR_LEN);
	  strcpy(A[i],tmp);
	}
      }
    }
    fclose(fp);
    return A;
  }
}

/////////////////////////////////////////////////////////////
// write words to a text file
/////////////////////////////////////////////////////////////
void write_chararr_textfile( const char outfile[], char *A[], int N )
  // write the given array of int string words, with its sie N
  // to file whose name given by outfile[]
  // uses print_chararr_array
{
  FILE *fp;

  // check for output filename
  if ( outfile == NULL ) {
    fprintf(stderr, "NULL file name\n");
    return;
  }

  // check for file existence
  fp = fopen(outfile,"w");
  if ( !fp ) {
    fprintf(stderr, "cannot open file for write %s\n",outfile);
  }
  else {
    print_chararr_array(fp,A,N);
    fclose(fp);
  }
}

/////////////////////////////////////////////////////////////
// insertion sort
/////////////////////////////////////////////////////////////
void insertion_sort_chararr ( char* arr[], int n ) {
	//refered to pseudo Code in lecture Note
	int i, j;
	char key[MAX_STR_LEN];
	for(i=1;i<n;i++){
		strcpy(key, arr[i]);
		j=i-1;
		while(j>=0 && strcmp(arr[j],key)==1){
			strcpy(arr[j+1],arr[j]);
			j--;
		}
		strcpy(arr[j+1],key);
	} 
}

/////////////////////////////////////////////////////////////
// selection sort
/////////////////////////////////////////////////////////////
void selection_sort_chararr(char* arr[], const int n) {
	//refered to pseudo Code in lecture Note
	int i, j, smallest;
	char temp[MAX_STR_LEN];
	for(i=0;i<n;i++){
		smallest = i;
		for(j=i+1;j<n;j++){
			if(strcmp(arr[j],arr[smallest])==-1) smallest = j;
		}
		strcpy(temp,arr[i]);
		strcpy(arr[i],arr[smallest]);
		strcpy(arr[smallest],temp);
	}
}

/////////////////////////////////////////////////////////////
// bubble sort
/////////////////////////////////////////////////////////////
void bubble_sort_chararr (char* arr[], int n) {
	//refered to pseudo Code in lecture Note
	int i, j;
	char temp[MAX_STR_LEN];	
	for(i=0;i<n;i++){
		for(j=n-1;j>i;j--){
			if(strcmp(arr[j],arr[j-1])==-1){
				strcpy(temp,arr[j]);
				strcpy(arr[j],arr[j-1]);
				strcpy(arr[j-1],temp);
			}
		}
	}
}

/////////////////////////////////////////////////////////////
// main function
/////////////////////////////////////////////////////////////
int main()
  /* Input file name by scanf read, typed in the terminal */
{
  int i, numElements;
  char** A;	// to store data to be sorted

  /* for file name, max length 1023 including path */
  char infile[1024], outfile[1024];
  int method;	// which sorting method

  /* file name given by keyboard */
  printf("Input file name? ");
  scanf("%s",infile);
  printf("Output file name? ");
  scanf("%s",outfile);

  printf("Method (1: insertion, 2: selection, 3: bubble)? ");
  scanf("%d",&method);

  /* read text file of words:
   * number_of_intergers word1 word2 ... */
  A = read_chararr_textfile(infile, &numElements);

  if ( A != NULL && numElements > 0 ) {
    switch ( method ) {
      case 1:	// insertion sort
	//insertion_sort(A, numElements);
	insertion_sort_chararr(A, numElements);
	break;
      case 2:	// selection sort
	//selection_sort(A, numElements);
	selection_sort_chararr(A, numElements);
	break;
      case 3:	// bubble sort
	//bubble_sort(A, numElements);
	bubble_sort_chararr(A, numElements);
	break;
      default:
	break;
    }

    // save results
    write_chararr_textfile(outfile, A, numElements);

    // once allocated, should be freed after use
    for (i=0; i<numElements; i++) free(A[i]);
    free(A);
  }

  return 0;
}

