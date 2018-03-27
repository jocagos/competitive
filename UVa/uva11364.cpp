#include <stdio.h>

int main()
{
  int T, N, L, R, arr[100];
  scanf("%d", &T);
  while(T--){
    L = 100, R = -1;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
      scanf("%d", &arr[i]);
      if( arr[i] < L ) L = arr[i];
      if( arr[i] > R ) R = arr[i];
    }
    printf("%d\n",2*(R-L));
  }
  return 0;
}
