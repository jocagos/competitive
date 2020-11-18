#include <bits/stdc++.h>

using namespace std;
constexpr long long MAXN = 1010;

long long a[MAXN] {};

long long bin_exp_mod( long long a, long long b, long long m ){
  long long res = 1LL;
  while( b > 0 ){
    if( b & 1 ) res = (res * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for( int tc = 1; tc <= t; ++ tc ){
    long long n, k, m, s = 0;
    cin >> n >> k >> m;
    for( int i = 0; i < n; ++ i ){
      cin >> a[i];
      s += a[i];
    }
    cout << "Case " << tc << ": " << (((s * bin_exp_mod( n, k - 1, m )) % m) * k) % m << endl;
  }
  return 0;
}
