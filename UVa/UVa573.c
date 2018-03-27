#include <stdio.h>
#define abs(x) ( (x) >= 0 ? (x) : (-(x)) )
int main(){
  int h, f, i;
  double d, u;
  char s[] = "success on day ";
  char fail[] = "failure on day ";
  double dist = 0.0;
  int t = 1;
  while(scanf("%d %lf %lf %d", &h, &u, &d, &f), h){
    i = 1; double _f = u * f / 100, c = u; dist = 0.0;
    while(1){
      if( c >= 0 ) dist += c;
      if( dist - h > 1e-9 ) break;
      c -= _f;
      dist -= d;
      if( dist < 0 ) break;
      i++;
    }
    if( dist < 0 ) printf("%s%d\n", fail, i);
    else printf("%s%d\n", s, i);
    t++;
  }
  return 0;
}
