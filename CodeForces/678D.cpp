#include <bits/stdc++.h>

using namespace std;

constexpr long long MOD = 1000000007;

long long bin_exp_mod( long long a, long long b, long long m = MOD ){
  a %= m;
  long long ans = 1;
  while( b > 0 ){
    if( b & 1 ) ans = ans * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return ans;
}

inline long long inv( long long a, long long m = MOD ){
  return bin_exp_mod( a, m - 2, m );
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long a {}, b {}, n {}, x {};
  cin >> a >> b >> n >> x;
  // cerr << a << " " << b << " " << n << " " << x << endl;
  if( a == 1 ) cout << (x + n % MOD * b)%MOD << endl;
  else{
    long long res = bin_exp_mod( a, n ) * x % MOD;
    res += (bin_exp_mod(a, n) - 1) * inv(a - 1) % MOD * b;
    cout << (res % MOD + MOD) % MOD << endl;
  }
  return 0;
}
