#include <stdio.h>

int main(){
  int n;
  while( scanf("%d", &n), n ){
    long a, b, i, idx = 0;
    a = b = 0;
    for( i = 1; i <= n; i <<= 1 ){
      if( i & n ){
	idx++;
	if( idx % 2 ) a += i;
	else b += i;
      }
    }
    printf("%ld %ld\n", a, b);
  }
  return 0;
}
