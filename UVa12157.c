#include <stdio.h>
#include <math.h>

int main(){
  int t, n, min = 670, i, j, d[20], mile = 0, juice = 0;
  scanf("%d", &t);
  for( i = 0; i < t; ++i ){
    scanf("%d", &n);
    mile = juice = 0;
    for( j = 0; j < n; ++j ){
      scanf("%d", &d[j]);
      mile += ceil(1.0*(d[j]+1)/30) * 10;
      juice += ceil(1.0*(d[j]+1)/60) * 15;
      min = ( mi
    }
    
  }
  return 0;
}
