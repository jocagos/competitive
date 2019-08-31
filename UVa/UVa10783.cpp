#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
  int t, a, b, sum;
  scanf("%d", &t);
  for( int _i = 1; _i <= t; ++_i ){
    sum = 0;
    printf("Case %d: ", _i);
    scanf("%d %d ", &a, &b);
    if( a == b && a % 2 ) printf("%d\n", a);
    else if( a == b && a % 2 == 0 ) printf("0\n");
    else{
      int tmp = a;
      a = min(a, b);
      b = max(tmp, b);
      if( a % 2 == 0 ) a++;
      if( b % 2 == 0 ) b--;
      for( int i = min(a, b); i <= max(a, b); i += 2 ) sum += i;
      printf("%d\n", sum);
    }
  }
  return 0;
}
