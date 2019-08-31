#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using i64 = unsigned long long;
using vi = vector<int>;
#define REP( a, b ) for( int a{}; a < b; ++ a )
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
constexpr ll MOD = 986444689;
constexpr ll MAX = 1e5 + 100;

ll n, k, t;
// vi ns( MAX ), ks( MAX );
vector<ll> f( MAX );

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

inline ll inv( ll a, ll m = MOD ){
  cerr << "inv( " << a << ", " << MOD - 2 << " ) = "
       << bin_exp_mod( a, MOD - 2 ) << endl;
  return bin_exp_mod( a, MOD - 2 );
}

void init(){
  // factorial
  f[0] = 1;
  for( int i = 1; i < MAX; ++ i ) f[i] = f[i - 1] * i % MOD;
}

inline ll ans( ll n, ll k ){
  cerr << "f[" << n << "] = " << f[n] << endl
       << "f[" << k << "] = " << f[k] << endl
       << "inv(f[" << k << "]) = " << inv(f[k]) << endl
       << "f[" << n - k << "] = " << f[n -k] << endl
       << "inv(f[" << n - k << "]) = " << inv(f[n -k]) << endl;
  return ((f[n] * (inv(f[k]) % MOD) % MOD) * (inv(f[n - k]) % MOD)) % MOD;
}



int main(){
  fastio;
  init();
  string line;
  getline( cin, line );
  t = stoi( line );
  while( t -- ){
    getline( cin, line );
    istringstream iss( line );
    iss >> n >> k;
    getline( cin, line );
    // istringstream iss2( line );
    // int idx = 0, tmp;
    // while( iss >> tmp ) ns[idx ++] = tmp;
    getline( cin, line );
    // istringstream iss3( line );
    // idx = 0;
    // while( iss >> tmp ) ks[idx ++] = tmp;
    cout << ans( n + k - 1, n - 1 ) << '\n';
  }
  return 0;
}
