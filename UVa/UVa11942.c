#include <stdio.h>

int main(){
  int t, lesser = 0, greater , n = 10, prev, this, i, j;
  scanf("%d", &t);
  printf("Lumberjacks:\n");
  for( i = 0; i < t; ++i ){
    lesser = greater = 0;
    n = 10;
    for( j = 0; j < n; ++j){
      if( j ) prev = this;
      scanf("%d", &this);
      if( j ){
        if( prev < this ) lesser++;
        if( prev > this ) greater++;
      }
    }
    if( ( lesser && !greater ) || ( greater && !lesser ) ) printf("Ordered\n");
    else printf("Unordered\n");
  }
  return 0;
}
