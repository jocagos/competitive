#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i64 = unsigned long long;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
constexpr ll MOD = 1e9 + 7;
ll bin_exp_mod( ll a, ll b, ll m = MOD ){
  a %= m;
  i64 res = 1;
  while( b > 0 ){
    if( b & 1 ) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
ll t, m, n, p, q;
int main(void){
  fastio;
  cin >> t;
  while( t -- ){
    cin >> m >> n >> p >> q;
    cout << 2LL * (m + n) % MOD * ((bin_exp_mod( p, q + 1 ) - 1) * bin_exp_mod( p - 1, MOD - 2 ) % MOD) % MOD << '\n';
  }
  return 0;
}
