#include <bits/stdc++.h>

using namespace std;
using i64 = long long int;
using ll = tuple<i64, i64>;
constexpr i64 MOD = 1000000007, INF = 1e9 + 107, MAXN = 1001000;
vector<i64> f( MAXN, -1 );

i64 fact( i64 n ){
  if( n < MAXN ){
    if( f[n] != -1 ) return f[n];
    else return f[n] = ((n * fact( n - 1 )) % MOD);
  }
  else{
    i64 t = f[MAXN-1];
    for( i64 i = MAXN; i <= n; ++ i )
      t = t * i % MOD;
    return t;
  }
}

i64 bin_exp( i64 b, i64 e, i64 m = MOD ){
  b %= m;
  i64 res = 1;
  while( e > 0 ){
    if( e & 1 ) res = res * b % m;
    b = b * b % m;
    e >>= 1;
  }
  return res;
}

i64 minv( i64 n, i64 m = MOD ){
  return bin_exp( n, m - 2 );
}

i64 comb( i64 n, i64 k ){
  if( n < k ) return 0;
  return fact( n ) / (fact( k ) * fact( n - k ));
}

i64 ans( i64 n, i64 t, i64 m ){
  i64 q = comb( n, t );
  i64 p = (q - comb( n - t, m )) % MOD;
  q = minv( q ) % MOD;
  return (p * q) % MOD;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  f[0] = f[1] = 1;
  int tc {}, t {}, n {}, m {};
  cin >> tc;
  while( tc -- ){
    cin >> n >> t >> m;
    if( n - t < m )
      cout << 1 << '\n';
    else
      cout << ans( n, t, m ) << '\n';
  }
  return 0;
}
