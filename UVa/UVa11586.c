#include <stdio.h>

int main(){
  int t; int b = 0;
  scanf("%d", &t);
  while( t-- ){
    char c;
    int m = 0, f = 0;
    c = getchar();
    while( c != '\n' && c != '\r' && c != '\v' ){
      if( c == 'M' ) m++;
      if( c == 'F' ) f++;
      c = getchar();
    }
    if( m == f ) printf("LOOP\n");
    else printf("NO LOOP\n");
  }
  return 0;
}
