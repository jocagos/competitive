#include <stdio.h>

int abs(int n){
  if( n > 0 )
    return n;
  else
    return -n;
}

int main()
{
  int T, N;
  scanf("%d", &T);
  while(T--){
    scanf("%d", &N);
    printf("%d\n", abs((235*(63*N +7492)/47-498)/10 % 10));
  }
  return 0;
}
