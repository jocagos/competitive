#include <stdio.h>

int main(){
  int T, N, B = 0, i = 1;
  do{
    scanf("%d", &T);
    if(T == 0)
      break;
    for(int ii = 0; ii < T; ++ii){
      scanf("%d", &N);
      if( N > 0 ) B++;
      else B--;
    }
    printf("Case %d: %d\n", i++, B);
    B = 0;
  }
  while(true);
  return 0;
}
