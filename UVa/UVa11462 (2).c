#include <stdio.h>
#include <stdlib.h>

int main(){
  int n, i, arr[100], t, last = 0;
  for( i = 0; i < 100; ++i) arr[i] = 0;
  scanf("%d", &n);
  while(n){
    for( i = 0; i < n; ++i ){
      scanf("%d", &t);
      arr[t]++;
      if( t > last ) last = t;
    }
    for( i = 0; i < 100; ++i )
      if( arr[i] ) for( t = 0; t < arr[i]; ){
	  printf("%d%c", i, (i == last && arr[i] == 1 ? '\n' : ' ' ));
	  arr[i]--;
	}
    last = 0;
    scanf("%d", &n);
  }
  return 0;
}
