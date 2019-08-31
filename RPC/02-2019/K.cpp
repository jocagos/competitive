#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1000100;
constexpr double eps = 1e-7;
using i64 = long long;

i64 der[MAXN], fac[MAXN];

i64 d( i64 n ){
  if( der[n] != -1 ) return der[n];
  return der[n] = (n - 1) * ( d( n - 1 ) + d( n - 2 ) );
}

i64 f( i64 n ){
  if( fac[n] != -1 ) return fac[n];
  return fac[n] = n * f( n - 1 );
}

int main(){
  memset( der, -1, sizeof der );
  memset( fac, -1, sizeof fac );
  der[0] = 1;
  der[1] = 0;
  fac[0] = fac[1] = 1;
  bool found = false;
  for( int i = 1; i < MAXN and not found; ++ i ){
    long double p = 1.0L - d( i ) / f( i ),
      q = 1.0L - d( i - 1 ) / f( i - 1 );
    if( abs( p - q ) < eps ) cout << "Index is " << i
			          << "\tp = " << p
				  << "\tq = " << q
				  << '\n', found = true;
  }
  return 0;
}
