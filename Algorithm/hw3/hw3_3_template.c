/* ID COMP319001        - 2016115572
 * NAME Algorithm       - Kwon Hyeon Su */

//////////////////////////////////////////////////////////////////
// If you have referred any code, leave the comments like this
// to avoid "COPY"
// SOURCE for heapify: i didn't referred source code. but referred how it works by watching pictures in https://o-tantk.github.io/posts/finding-median/
///////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEASURE_TIME	// to measure execution time
// from GJANG: not sure if the time measurement code works with Windows
// If it works, execution time will be printed.
// Otherwise, comment out the line "#define MEASURE_TIME" and compile again.

/////////////////////////////////////////////////////////////////////
// to compute execution time in seconds
/////////////////////////////////////////////////////////////////////
#ifdef MEASURE_TIME
#include<time.h>
#endif

/////////////////////////////////////////////////////////////////////
// homework programming assignment 3-3
/////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
// function to find median using min heap and max heap
// to find median value from an array, use the following heap architecture
// 1) store all the data to heap L and heap R
// 2) all values in L < any value in R
// 3) if the number of total items is N,
//   odd  N: number of items in L = N/2+1, number of items in R = N/2
//   even N: number of items in L = number of items in R = N/2
//     i.e. n_L = n_R or n_L = n_R+1
// 4) keep L as max heap, keep R as min heap, then the median is root(L)
//   *in many definitions of median, when N is even, the median is
//    defined as an average of item N/2 and item N/2+1, but we assume
//    it is root(L) (item ceiling(N/2)) to make the problem simple
//   *all values in L <= root(L), so it also satisfies definition of median
//   *Reference:
// https://www.quora.com/How-do-you-find-the-median-from-a-set-of-even-numbers
// https://www.dkfindout.com/us/math/averages/more-about-medians/
//
// What to do:
// 1) Implement
//    Heap4Median_AddItem(int L[], int *p_n_L, int R[], int *p_n_R, int value)
//    to add a value to L and R
//    heaps L and R should satisfy the above conditions
// 2) Implement
//    Heap4Median_Build(int A[], int N, int L[], int *p_n_L, int R[], int *p_n_R)
//    For an unsorted array, it builds heaps L and R from empty heaps
//    A: size N array
//    L: size ceil(N/2) array,  R: size floor(N/2) array
//    the array memory should be allocated in advance
// 3) Implement
//    Heap4Median_Sort(int L[], int n_L, int R[], int n_R, int A[], int p_N)
//    For Heap4Median given by L and R (with their number of elements by n_L and n_R)
//    fill the array A in an ascending order
///////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////

void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int root(int A[]){
	return A[1];
}

/*
void printfHeap(int A[], int N){
	int i;
	printf("----------------------\n");
	if(N == 0) printf("None");
	else for(i=1;i<=N;i++) printf("%d \n", A[i]);
	printf("\n----------------------\n");
	printf("\n");
}*/

void MaxHeapify(int A[], int N, int i){
	int l = i*2;
	int r = i*2+1;
	int largest;
	
	if(l<=N && A[l]>A[i]) largest = l;
	else largest = i;
	
	if(r<=N && A[r]>A[largest]) largest = r;
	
	if(largest != i){
		swap(&A[largest], &A[i]);
		MaxHeapify(A, N, largest);
	}
}
/*
void BuildMaxHeap(int A[], int N){
	int i;
	for(i=N/2;i>0;i--) MaxHeapify(A, N, i);
}
*/
void BuildMaxHeap_op(int A[], int N){
	int i;
	for(i=N/2;i>0;i/=2) MaxHeapify(A, N, i);
}

void MinHeapify(int A[], int N, int i){
	int l = i*2;
	int r = i*2+1;
	int smallest;
	
	if(l<=N && A[l]<A[i]) smallest = l;
	else smallest = i;
	
	if(r<=N && A[r]<A[smallest]) smallest = r;
	
	if(smallest != i){
		swap(&A[smallest], &A[i]);
		MinHeapify(A, N, smallest);
	}
}
/*
void BuildMinHeap(int A[], int N){
	int i;
	for(i=N/2;i>0;i--) MinHeapify(A, N, i);
}*/

void BuildMinHeap_op(int A[], int N){
	int i;
	for(i=N/2;i>0;i/=2) MinHeapify(A, N, i);
}

void heap_insert_item(int A[], int* p_N, int value){
	(*p_N)++;
	A[*p_N] = value;
}

/////////////////////////////////////////////////////////////////////

void Heap4Median_AddItem(int L[], int *p_n_L, int R[], int *p_n_R, int value)
{
	int i;

	if(*p_n_L == 0 && *p_n_R == 0) heap_insert_item(L, p_n_L, value);
	
	else if(value <= root(L)){
		if(*p_n_L>*p_n_R) { 
			heap_insert_item(R, p_n_R, root(L));
			L[1] = value;
			BuildMaxHeap_op(L, *p_n_L);
			BuildMinHeap_op(R, *p_n_R);
		}
		else{
			heap_insert_item(L, p_n_L, value);
			BuildMaxHeap_op(L, *p_n_L);
		}
	}
	else{
		if(*p_n_L == *p_n_R){
			if(root(R)>value){
				heap_insert_item(L, p_n_L, value);
				BuildMaxHeap_op(L, *p_n_L);
			}else{
				heap_insert_item(L, p_n_L, root(R));
				R[1] = value;
				BuildMaxHeap_op(L, *p_n_L);
				BuildMinHeap_op(R, *p_n_R);
			}
		}
		else{
			heap_insert_item(R, p_n_R, value);
			BuildMinHeap_op(R, *p_n_R);
		}
	}
}

void Heap4Median_Build(int A[], int N, int L[], int *p_n_L, int R[], int *p_n_R)
{
	int i;
	*p_n_L = *p_n_R = 0;

	
	for(i=1;i<=N;i++){
		Heap4Median_AddItem(L, p_n_L, R, p_n_R, A[i]);
		/*
		printf("i : %d, value : %d\n", i, A[i]);
		printf("L\n");
		printfHeap(L,*p_n_L);
		printf("R\n");
		printfHeap(R,*p_n_R);
		
		printf("p_n_L : %d, p_n_R : %d\n",*p_n_L, *p_n_R);
		*/
	}
}

void Heap4Median_Sort(int L[], int n_L, int R[], int n_R, int A[], int *p_N)
{
    int i;
    int t_n_L = n_L;
    int t_n_R = n_R; 
	for(i=n_L;i>1;i--){
		swap(&L[1],&L[i]);
		t_n_L--;
		MaxHeapify(L, t_n_L, 1);
	}
	for(i=n_R;i>1;i--){
		swap(&R[1],&R[i]);
		t_n_R--;
		MinHeapify(R, t_n_R, 1);
	}
    
    if((*p_N)%2 == 0){
	    for(i=1;i<=(*p_N)/2;i++){
	    	A[i] = L[i];
	    	A[(*p_N)/2+i] = R[n_R+1-i];
	    }
    }else{
    	for(i=1;i<=(*p_N)/2+1;i++){
	    	A[i] = L[i];
	    	
	    }
	for(i=1;i<=(*p_N)/2;i++){
	    A[(*p_N)/2+1+i] = R[n_R+1-i];
	}
    }
    printf("\n");
}

/////////////////////////////////////////////////////////////////////
// test your implementation 
/////////////////////////////////////////////////////////////////////
int main()
{
  int i, N;
  int *A, *L, *R;
  int n_L, n_R;

  // 0. read input 
  fscanf(stdin, "%d", &N);
	
	
  // allocate interger arrays and read input values
  // In the textbook, the array indexing is 1-based (i.e. starts with 1)
  // so this template code is written for 1-based indexing
  // (starts with 1, leaving A[0] untouched.
  // If you prefer 0-based indexing, you may modify the example code below
  // ex.) "for (i=1; i<=N; i++) " --> "for (i=0; i<N; i++) "
  // "median = L[1]; " --> "median = L[0]; "
  A = (int*)malloc(sizeof(int)*(N+1));
  for (i=1; i<=N; i++) {
    if ( fscanf(stdin, "%d", A+i) != 1 ) {
      fprintf(stderr, "cannot read integer from standard input.\n");
      free(A);
      exit(0);
    }
  }
	
  L = (int*)malloc(sizeof(int)*(N/2+1+1));
  R = (int*)malloc(sizeof(int)*(N/2+1+1));

#ifdef MEASURE_TIME
  clock_t start, end;
  double cpu_time_used;

  start = clock();
#endif
  /////////////////////////////////////////////////////////////////////
  // ***FILL*** :  invoke Heap4Median_Build(...) to obtain sub-heaps L and R
  /////////////////////////////////////////////////////////////////////
  Heap4Median_Build(A, N, L, &n_L, R, &n_R);

  // output for evaluation: print median only
  fprintf(stdout,"L[1] :%d\n",L[1]);

  Heap4Median_Sort(L, n_L, R, n_R, A, &N);

#ifdef MEASURE_TIME
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  fprintf(stderr,">> Execution time: %.5f seconds\n",cpu_time_used);
#endif

  // output for evaluation: sorted list
  for (i=1; i<=N; i++) fprintf(stdout, "%d ", A[i]);
  fprintf(stdout, "\n");
  
  // free memory
  free(A);
  free(L);
  free(R);
	
  return 0;
}

