#include <stdio.h>

int main(){
  int t, n, max, c, i;
  scanf("%d", &t);
  for( i = 0; i < t; ++i ){
    scanf("%d", &n);
    max = 0;
    while(n--){
      scanf("%d", &c);
      if( max < c ) max = c;
    }
    printf("Case %d: %d\n", i+1, max);
  }
  return 0;
}
