#include <stdio.h>

int main(){
  int n, b, h, w, i, min;
  while(scanf("%d %d %d %d", &n, &b, &h, &w) != EOF){
    min = 500001;
    while(h--){
      int c, night, aval = 0, valid = -1;
      scanf("%d", &c);
      if( c * n > b ) valid = 0;
      for( i = 0; i < w; ++i ){
        scanf("%d", &night);
        if( !valid ) continue;
        if( aval ) continue;
        if( night >= n ) aval = 1;
      }
      if( valid && aval && min > c * n ) min = c * n;
    }
    if( min < 500001 ) printf("%d\n", min);
    else printf("stay home\n");
  }
  return 0;
}
