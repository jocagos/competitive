#include <cstdio>
#include <algorithm>

using namespace std;
constexpr int MAX_VALS = 6, MAX_FACE = 50;
constexpr int MAX_T2 = 12, MAX_T3 = 8;

int main(){
  long long n {};
  long long vals[MAX_VALS] {};
  long long t2[MAX_T2] {}, t3[MAX_T3] {};
  scanf("%lld", &n);
  for( int i = 0; i < MAX_VALS; ++ i )
    scanf("%lld", &vals[i]);
  if( n == 1 ){
    sort( vals, vals + MAX_VALS );
    long long sum {};
    for( int i = 0; i < MAX_VALS - 1; ++ i )
      sum += vals[i];
    printf("%lld\n", sum);
  }
  else{
    // pairs, as sums
    t2[ 0] = vals[0] + vals[1]; // a + b
    t2[ 1] = vals[0] + vals[2]; // a + c
    t2[ 2] = vals[0] + vals[3]; // a + d
    t2[ 3] = vals[0] + vals[4]; // a + e
    t2[ 4] = vals[1] + vals[2]; // b + c
    t2[ 5] = vals[1] + vals[3]; // b + d
    t2[ 6] = vals[1] + vals[5]; // b + f
    t2[ 7] = vals[2] + vals[4]; // c + e
    t2[ 8] = vals[2] + vals[5]; // c + f
    t2[ 9] = vals[3] + vals[4]; // d + e
    t2[10] = vals[3] + vals[5]; // d + f
    t2[11] = vals[4] + vals[5]; // e + f
    // 3-tuples, as sums
    t3[0] = vals[0] + vals[1] + vals[2]; // a + b + c
    t3[1] = vals[0] + vals[1] + vals[3]; // a + b + d
    t3[2] = vals[0] + vals[2] + vals[4]; // a + c + e
    t3[3] = vals[0] + vals[3] + vals[4]; // a + d + e
    t3[4] = vals[1] + vals[2] + vals[5]; // b + c + f
    t3[5] = vals[1] + vals[3] + vals[5]; // b + d + f
    t3[6] = vals[2] + vals[4] + vals[5]; // c + e + f
    t3[7] = vals[3] + vals[4] + vals[5]; // d + e + f
    sort( t2, t2 + MAX_T2 );
    sort( t3, t3 + MAX_T3 );
    // continue the cases
    if( n == 2 ){
      long long ans = 4 * t2[0] + 4 * t3[0];
      printf("%lld\n", ans);
    }
    else{
      sort( vals, vals + MAX_VALS );
      long long ans = 4LL * (n - 1LL) * t2[0] + 4LL * (n - 2LL) * t2[0]
	+ 4 * t3[0] + 5 * (n - 2LL) * (n - 2LL) * vals[0]
	+ 4 * (n - 2) * vals[0];
      printf("%lld\n", ans);
    }
  }
  return 0;
}
