#include <stdio.h>

int main(){
  int t;
  scanf("%d ", &t);
  while(t--){
    int h, m;
    scanf("%d:%d ", &h, &m);
    if( h < 12 ) h = 12 - h;
    if( m > 0 ) m = 60 - m, h--;
    if( h == 0 ) h += 12;
    printf("%02d:%02d\n", h, m);
  }
  return 0;
}
