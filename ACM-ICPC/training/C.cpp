#include <bits/stdc++.h>
#define MOD 100000007
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

vector<ll> dp( 10010, -1 );

inline ll f( ll k ){ return k * ( 3 * k - 1 ); }

ll p( ll n ){
  if( n < 0 ) return 0;
  if( dp[n] != -1 ) return dp[n];
  else{
    ll s = 1, r = 0;
    for( int k = 1; k < n + 1; ++ k ){
      ll t = n - f(k) / 2;
      ll t1 = p( t ), t2 = p( t + 1 );
      if( t >= 0 ) dp[t] = t1;
      if( t + 1 >= 0 ) dp[t + 1] = t2;
      r = s * ( t1 + t2 ) % MOD;
      s = -s;
    }
    return dp[n] = r;
  }
}

int main(){
  int n;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while( cin >> n ) cout << p(n) << '\n';
  return 0;
}
