#include <stdio.h>
#define min(a, b) ( (a) < (b) ? (a) : (b))
#define max(a, b) ( (a) > (b) ? (a) : (b))
#define abs(a) ( (a) >= 0 ? (a) : (-(a)))

int main(){
  int t, a, b, i;
  scanf("%d %d", &a, &b);
  while(a != -1 && b != -1){
    if( abs( a - b ) > 50 )
      printf("%d\n", abs(min(a,b)+100 - max(a,b)));
    else
      printf("%d\n", abs( a - b ) );
    scanf("%d %d", &a, &b);
  }
  return 0;
}
