#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int h, m;
  while( scanf("%d:%d ", &h, &m), h || m ){
    double alpha;
    h %= 12;
    h *= 30;
    h += m / 2.0;
    m *= 6;
    alpha = fabs( h - m );
    if( alpha > 180 ) alpha = 360 - alpha;
    printf("%.3f\n", alpha);
  }
  return 0;
}
