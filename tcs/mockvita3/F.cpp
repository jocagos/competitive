#include <bits/stdc++.h>

using namespace std;

constexpr long long int MOD = 1000000007, MAXN = 1000100;
long long dp[MAXN] {};

// void init(){
//   for( int i = 3; i < MAXN; ++ i ){
//     dp[i] 
//   }
// }

long long ways( long long left, bool unused = true ){
  if( left <= 0 ) return 1;
  if( dp[left] != -1 ) return dp[left];
  return dp[left] = (ways( left - 1, unused ) % MOD + ways( left - 2, unused ) % MOD + (unused ? ways( left - 3, false ) % MOD : 0 ) ) % MOD;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for( int i = 0; i < MAXN; ++ i ) dp[i] = -1;
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;
  long long n {};
  cin >> n;
  ways( 150000 );
  ways( 250000 );
  ways( 400000 );
  ways( 550000 );
  ways( 700000 );
  ways( 850000 );
  cout << ways( n ) << endl;
  return 0;
}
