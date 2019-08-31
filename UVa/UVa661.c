#include <stdio.h>

int main(){
  int n, i, m, c, sum = 0, blown = 0, max = 0, _t = 0;
  char mx[] = "Fuse was not blown.\nMaximal power consumption was ";
  char am[] = " amperes.\n";
  char bl[] = "Fuse was blown.\n";
  int d[21] = {0};
  int bitmask = 0;
  while( scanf("%d %d %d", &n, &m, &c), n || m || c ){
    int t; _t++;
    sum = 0; bitmask = 0; blown = 0; max = 0;
    for(i = 1; i <= n; ++i )
      scanf("%d", &d[i]);
    for( i = 0; i < m; ++i ){
      scanf("%d", &t);
      if( bitmask & (1 << (t)) ){
	sum -= d[t]; bitmask ^= (1 << (t));
      } else{
	sum += d[t]; bitmask ^= (1 << (t));
      }
      if( sum > max ) max = sum;
      if( sum > c ) blown = 1;
    }
    printf("Sequence %d\n", _t);
    if( blown ) printf("%s\n", bl);
    else printf("%s%d%s\n", mx, max, am);
  }
  return 0;
}
