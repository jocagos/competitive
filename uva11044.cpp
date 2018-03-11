#include <stdio.h>

int main()
{
  int T, M, N;
  scanf("%d", &T);
  while(T--){
    scanf("%d %d", &M, &N);
    printf("%d\n", (M/3)*(N/3));
  }
  return 0;
}
