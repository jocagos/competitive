#include <stdio.h>

int main(){
  int t, v[10], i, max = -1, j;
  char web[10][101];
  scanf("%d", &t);
  for( i = 0; i < t; ++i ){
    max = -1;
    for( j = 0; j < 10; ++j ){
      scanf("%s %d", web[j], &v[j]);
      if( max < v[j] ) max = v[j];
    }
    printf("Case #%d:\n", i+1);
    for( j = 0; j < 10; ++j ){
      if( v[j] == max ) printf("%s\n", web[j]);
    }
  }
  return 0;
}
