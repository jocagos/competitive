#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MAXP = 7223LL; // max number of patients

inline ll f( ll m, ll d ){
  return (6 - m) * (6 - m) + abs(d - 15);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll n {}, tv1 {}, tv2 {}, target {};
  vector<int> mdays { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  cin >> n >> tv1 >> tv2 >> target;
  ll min_tv {n + 1};
  for( int m = 0; m <= n; ++ m ){
    ll su {};
    for( int M = 1; M <= 12; ++ M ){
      for( int D = 1; D <= mdays[M-1]; ++ D ){
	ll p = min( f( M, D ), n );
	ll left = min( p, n - m );
	ll right = p - left;
	su += left * tv2 + right * tv1;
      }
    }
    if( su >= target and min_tv > m ) min_tv = m;
  }
  cout << min_tv << endl;
  return 0;
}
