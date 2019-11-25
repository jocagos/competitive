#include <bits/stdc++.h>

using namespace std;
constexpr long MAXN = 10000010;
long long memo[MAXN] {};

long long f( long long n ){
  long long k = n;
  if( memo[n] ) return memo[n];
  if( n == 1LL ) return memo[1] = 3;
  long long c = 0;
  while( n != 1 ){
    if( n % 2 ) n = 3 * n + 1;
    else n >>= 1;
    ++ c;
  }
  return memo[k] = c;
}

int main(){
  long long left, right;
  // memo[1] = 3;
  while( scanf( "%lld %lld\n", &left, &right ), left | right ){
    if( left == 0 ) break;
    long long m = f( min( left, right ) ), mi = min( left, right );
    for( long long i = min( left, right ) + 1; i <= max( left, right ); ++ i ){
      long long tmp = f( i );
      if( tmp > m ){
	m = tmp;
	mi = i;
      }
    }
    printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n", min(left, right), max(left, right), mi, m);
  }
  return 0;
}
