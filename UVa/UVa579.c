#include <stdio.h>
#include <math.h>

int main(){
  int h, m;
  while( scanf("%d:%d ", &h, &m), h || m ){
    printf("%.3f\n", (fabs( (h%12)*30 + m / 2.0 - m*6 ) > 180 ? 360 - fabs( (h%12)*30 + m / 2.0 - m*6 ) : fabs( (h%12)*30 + m / 2.0 - m*6 ) ) );
  }
  return 0;
}
