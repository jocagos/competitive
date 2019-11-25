#include <bits/stdc++.h>

using namespace std;
constexpr long long MOD = 1e9 + 7;

long long n, p;
vector<long long> coins, amount;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> p;
  long long b = 1, prev = 1;
  while( b <= n ){
    coins.emplace_back( b );
    b *= p;
    amount.emplace_back( n % b / prev );
    prev *= p;
  }
  long long ans {};
  for( int i = 1; i < (int)amount.size(); ++ i ){
    ans = ans + 
  }
  return 0;
}
