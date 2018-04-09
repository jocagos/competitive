#include <stdio.h>
#define abs(x) (x) > 0 ? (x) : (-(x))
#define max(x, y) ( (x) + (y) + (abs( (y) - (x) )) ) / 2
#define f(h, m) (60 * (h) + (m))

int main(){
  int hl, ml, hr, mr;
  while( scanf("%d %d %d %d ", &hl, &ml, &hr, &mr), hl || ml || hr || mr ){
    printf("%d\n", (f(hl, ml) > f(hr, mr) ? f(hr, mr) - f(hl, ml) + 1440 : f(hr, mr) - f(hl, ml)) );
  }
  return 0;
}
