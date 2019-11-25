#include <bits/stdc++.h>

using namespace std;
constexpr long long int MOD = 1000000007;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n {};
  cin >> n;
  cout << ( n * (n + 1LL) % MOD * 7LL / 2LL - 5LL ) % MOD << '\n';
  return 0;
}
