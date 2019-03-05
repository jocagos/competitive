#include <stdio.h>
#include <stdlib.h>
#define valOf(x) printf("%s: %lld\n", #x, x)

long long mergeSort(int *, int *, int);
long long splitMerge(int *, int, int, int *);
long long merge(int *, int, int, int, int *);
void arrcpy(int *, int, int, int *);

long long inv = 0;

int main(){
  int n = -1, *arr, i, j;
  scanf("%d", &n);
  while(n){
    inv = 0;
    arr = (int *) malloc( n * sizeof(int));
    int * cpy = (int *) malloc( n * sizeof(int) );
    for( i = 0; i < n; ++i ) scanf("%d", &arr[i]);
    long long inv = mergeSort( arr, cpy, n );
    for( i = 0; i < n; ++i) printf("%d%s", cpy[i], (i+1 == n ? "\n" : " " ) );
    /* printf("INVERSIONS: %lld\n", inv); */
    /*
    /* Add Merge_Sort
    
    if( inv % 2 ) printf("Marcelo\n");
    else printf("Carlos\n");
    */
    scanf("%d", &n);
    free(arr);
    free(cpy);
  }
  return 0;
}

long long mergeSort( int * A, int * B, int n )
{
  arrcpy(A, 0, n, B);
  return splitMerge(A, 0, n, B);
}

long long splitMerge( int * B, int begin, int end, int * A )
{
  if( end - begin < 2 ) return 0;
  int mid = (end + begin) / 2;
  long long a = splitMerge(A, begin, mid, B);
  printf("Left a = %lld\n", a);
  a += splitMerge(A, mid, end, B);
  printf("Right a = %lld\n", a);
  a += merge(B, begin, mid, end, A);
  printf("aMerged: %lld\n", a);
  return a;
}

long long merge( int * A, int begin, int mid, int end, int * B )
{
  int i = begin, j = mid, k;
  printf("begin = %d\tmid = %d\tend = %d\n", begin, mid, end);
  long long inv = 0;
  /*  for( k = begin; k < end; ++k ) printf("A[%d] = %d\tB[%d] = %d\n", k, A[k], k, B[k] );*/
  for( k = begin; k < end; k++ ){
    /*    printf("Before: B[%d] = %d\tA[%d] = %d\tA[%d] = %d\n", k, B[k], i, A[i], j, A[j]);*/
    if( A[i] > A[j] && A[j] != 0 ) printf("inv: %lld\tplus: %d\tReason: A[%d] > A[%d] (%d > %d)\n", inv, mid-i, i, j, A[i], A[j]), inv += (mid -i);
    if( i < mid && (j >= end || A[i] <= A[j]) )
    {
      B[k] = A[i];
      i = i+1;
    }
    else
    {
      B[k] = A[j];
      j = j+1;
    }
    /*    printf("After: B[%d] = %d\tA[%d] = %d\tA[%d] = %d\n", k, B[k], i, A[i], j, A[j]);*/
  }
  return inv;
  /*  printf("AFTER:\n");
  for( k = begin; k < end; ++k ) printf("A[%d] = %d\tB[%d] = %d\n", k, A[k], k, B[k] );
  printf("=====\n");*/
}

void arrcpy( int * A, int begin, int end, int * B )
{
  int i = 0;
  for( i = begin; i < end; ++i ) B[i] = A[i];
}
