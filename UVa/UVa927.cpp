#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

typedef unsigned long long ull;

int main(){
  int t;
  scanf("%d", &t);
  while( t-- ){
    int n, d, k;
    scanf("%d", &n);
    vector<int> an(n+1);
    for( int i = 0; i <= n; ++i ) scanf("%d", &an[i]);
    scanf("%d", &d); scanf("%d", &k);
    ull least_n = 1, p1 = 0, p2 = 0;
    for( least_n; ; least_n++ ){
      p2 = p1;
      p1 += least_n * d;
      if( p2 < k && k <= p1 ) break;
    }
    ull ans = 0;
    for( int i = 0; i <= n; ++i ) if( an[i] > 0 ) ans += an[i] * pow( least_n, i );
    printf("%llu\n", ans );
  }
  return 0;
}
