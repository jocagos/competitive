#include <stdio.h>

int main(){
  int t, i;
  scanf("%d", &t);
  int bus[100];
  for( i = 1; i <= t; ++i ){
    int k, h, m, b, j, at, min = 2440;
    scanf("%d %d:%d", &k, &h, &at);
    at += h*60;
    for( j = 0; j < k; ++j ){
      scanf("%d:%d %d", &h, &m, &b);
      bus[j] = (at > h*60 + m ? h*60+m+1440-at+b : h*60+m-at+b);
      if( bus[j] < min ) min = bus[j];
    }
    printf("Case %d: %d\n", i, min);
  }
  return 0;
}
