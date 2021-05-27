#include <cstdio>
#include <cmath>

using namespace std;

int main(){
  int P {}, C {}, G {};
  scanf("%d %d %d", &P, &C, &G);
  int ans = G;
  P -= G;
  if( P < 0 ) P = 0;
  ans += ceil( (P + 2 * C) / 4.0 );
  printf("%d\n", ans);
  return 0;
}
