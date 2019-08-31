#include <stdio.h>
#include <stdlib.h>
int main(){
  int t, n, s = 0, *arr, i, j;
  scanf("%d", &t);
  while(t--){
    scanf("%d", &n);
    arr = (int *) malloc(n * sizeof(n));
    for( i = 0; i < n; ++i) scanf("%d", &arr[i]);
/*  for( i = 0; i < n; ++i) printf("%d%c", arr[i], (i+1 == n ? '\n' : ' '));*/
    for( i = 0; i < n; ++i){
      for( j = i+1; j < n; ++j){
	if( arr[i] > arr[j] ){
/*	  printf("%d > %d\n", arr[i], arr[j]);*/
	  s++;
	}
      }
    }
    printf("Optimal train swapping takes %d swaps.\n", s);
    s = 0;
    free(arr);
  }
  return 0;
}
