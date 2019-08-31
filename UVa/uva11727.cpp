#include <stdio.h>

int main()
{
  int T, A, B, C;
  scanf("%d", &T);
  for(int i = 0; i < T; ++i){
    scanf("%d %d %d", &A, &B, &C);
    printf("Case %d: ", i+1);
    if( A > B and B > C or C > B and B > A)
      printf("%d\n", B);
    else if(A > C and C > B or B > C and C > A)
      printf("%d\n", C);
    else if(B > A and A > C or C > A and A > B)
      printf("%d\n", A);
  }
  return 0;
}
