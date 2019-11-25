#include <bits/stdc++.h>

using namespace std;
constexpr long MOD = 998244353, MAXN = 2 * 10e5;
vector<long long> _left( MAXN, 0 );

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, m {};
  long long ans{}, tmp{1};
  cin >> n >> m;
  string s {};
  cin >> s;
  for( int i = 0; i < n; ++ i ){
    if( s[n - i - 1] - '0' ) _left[i] = (_left[i] + tmp) % MOD;
    tmp = (tmp << 1) % MOD;
    if( i ) _left[i] += _left[i - 1];
  }
  for( int i = n; i < m; ++ i ) _left[i] = _left[i - 1];
  cin >> s;
  for( int i = 0; i < m; ++ i )
    if( s[m - i - 1] - '0' ) ans = (ans + _left[i]) % MOD;
  cout << ans << endl;
  return 0;
}
