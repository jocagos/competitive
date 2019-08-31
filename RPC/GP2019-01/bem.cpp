#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i64 = unsigned long long;
constexpr ll MOD = 986444689;
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

ll a, b, m;

int main( int argc, char* argv[] ){
  if( argc == 1 ){
    cin >> a >> b >> m;
  }
  else if( argc == 4 ){
    a = stoi( argv[1] ), b = stoi( argv[2] ), m = stoi( argv[3] );
  }
  cout << bin_exp_mod( a, b, m ) << endl;
  return 0;
}
