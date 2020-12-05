#include <iostream>

using namespace std;
constexpr long long MOD = 1000000007;

long long solve( long long k, long long n ){
  n = (n + 1) % MOD;
  long long start = ( k % 2LL ? k + 1 : k + 2 );
  start /= 2;
  start *= ( k % 2LL ? k + 2 : k + 1 );
  start %= MOD;
  return (start * n) % MOD;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n {}, k {};
  int tc {};
  cin >> tc;
  while( tc -- ){
    cin >> n >> k;
    cout << solve(n, k) << '\n';
  }
  return 0;
}
