#include <stdio.h>

int max(int *arr, int n){
  int m = arr[0];
  for(int i = 1; i < n; ++i)
    if( arr[i] > m)
      m = arr[i];
  return m;
}

int min(int *arr, int n){
  int m = arr[0];
  for(int i = 1; i < n; ++i)
    if( arr[i] < m )
      m = arr[i];
  return m;
}

int main()
{
  int T, N, L, R, *arr;
  scanf("%d", &T);
  while(T--){
    scanf("%d", &N);
    arr = new int[N];
    for(int i = 0; i < N; ++i){
      scanf("%d", &arr[i]);
    }
    L = min(arr, N);
    R = max(arr, N);
    printf("%d\n", 2*(R-L));
  }
  return 0;
}
