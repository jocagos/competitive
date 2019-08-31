#include <stdio.h>

int main(){
  int h, w;
  int v[10005];
  while( scanf("%d %d", &h, &w), h != 0 ){
    int i = 0, c;
    scanf("%d", &v[0]);
    c = h - v[0];
    for( i = 1; i < w; ++i ){
      scanf("%d", &v[i]);
      if( v[i] != h )
	if( v[i-1] - v[i] > 0 ) c += v[i-1] - v[i];
    }
    printf("%d\n", c);
  }
  return 0;
}
