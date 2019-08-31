#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i64 = unsigned long long;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

inline ll g( ll x, ll n ){
  return (x * x + 1) % n;
}

ll pollard_rho( ll n ){
  ll x = 2, y = 2, d = 1;
  while( d == 1 ){
    x = g( x, n );
    y = g( g( y, n ), n );
    d = __gcd( abs( x - y ), n );
  }
  if( d == n ) return -1;
  else return d;
}

ll t, n;
int main(void){
  fastio;
  cin >> t;
  while( t -- ){
    cin >> n;
    
  }
  return 0;
}
