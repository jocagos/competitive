#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 100100;

long double memo[MAXN] {};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  memo[0] = 0;
  for( int i = 1; i < MAXN; ++ i ) memo[i] = memo[i - 1] + 1. / (2 * i);
  int n{};
  cout << "# Cards Overhang\n";
  while( cin >> n ) cout << setw(5) << right << n << "     " << setprecision(3) << fixed << right << memo[n] << '\n';
  return 0;
}
