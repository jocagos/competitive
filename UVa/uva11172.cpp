#include <stdio.h>

int main()
{
  int T, A, B;
  scanf("%d", &T);
  while(T--){
    scanf("%d %d", &A, &B);
    printf("%c\n", (A > B) ? '>' : ((A < B) ? '<' : '='));
  }
  return 0;
}
