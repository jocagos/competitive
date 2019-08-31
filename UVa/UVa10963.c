#include <stdio.h>

int main(){
  int t, c, n, s, b;
  scanf("%d", &t);
  while(t--){
    b = 1;
    scanf("%d", &c);
    int d = -1;
    while(c--){
      scanf("%d %d", &n, &s);
      if( b ) {
	      if( d != -1 && n - s + 1 != d ) b = 0;
	      else d = n - s + 1;
      }
    }
    if( b ) printf("yes\n");
    else printf("no\n");
    if( t ) printf("\n");
  }
  return 0;
}
