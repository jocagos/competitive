#include <stdio.h>

int main(){
  int i, t, n, prev, this, low, high;
  scanf("%d", &t);
  for(i = 0; i < t; ++i){
    low = high = 0;
    prev = -1;
    scanf("%d", &n);
    int j;
    for( j = 0; j < n; ++j ){
      if( j ) prev = this;
      scanf("%d", &this);
      if( j ){
	if( prev > this ) low++;
	else if( prev < this ) high++;
      }
    }
    printf("Case %d: %d %d\n", i+1, high, low);
  }
  return 0;
}
