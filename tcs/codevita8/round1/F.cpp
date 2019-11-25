#include <iostream>
#include <cmath>
#include <deque>

using namespace std;
const int MAXN = 120, MAXK = 12, MOD = 17;
int a[120], pow2[120];

int bin_exp_mod( int a, int b, int m = MOD ){
  a %= m;
  int res = 1;
  while( b > 0 ){
    if( b & 1 ) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res % m;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T, n, k;
  pow2[0] = 1;
  for( int i = 1; i < MAXN; ++ i )
    pow2[i] = pow2[i - 1] * 2 % (MOD - 1);
  cin >> T;
  while( T -- ){
    cin >> n >> k;
    for( int i = 0; i < k; ++ i )
      cin >> a[i];
    int ans = 1;
    int diff = 0;
    if( n <= k ) cout << a[n - 1] << '\n';
    else if( k < n and n < 2 * k ){
      deque<int> exps;
      int max_exp = pow2[n - k - 1];
      for( int i = 0; i < n - k; ++ i ){
	exps.push_back( ((max_exp - diff) % 16 + 16) % 16 );
	if( diff == 0 ) diff = 1;
	else diff <<= 1;
      }
      for( int i = 0; i < 2 * k - n; ++ i ) exps.push_front( max_exp );
      for( int i = k - 1; i >= 0; -- i ){
	int tmp = exps.front();
	exps.pop_front();
	ans = ans * bin_exp_mod(a[i], tmp) % MOD;
      }
    }
    else{ // n >= 2k
      int max_exp = pow2[n - k - 1];
      int diff = 0;
      for( int i = k - 1; i >= 0; -- i ){
	int ex = ((max_exp - diff) % 16 + 16) % 16;
	ans = ans * bin_exp_mod( a[i], ex ) % MOD;
	if( diff == 0 ) diff = 1;
	else diff <<= 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
