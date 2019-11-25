#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 505;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  int pascal[MAXN][MAXN] {};
  pascal[0][1] = 1;
  for( int i = 1; i < MAXN; ++ i )
    for( int j = 1; j < MAXN; ++ j )
      pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
  double burger {};
  while( cin >> n >> burger, n ){
    double p[MAXN] {}, p1[MAXN] {};
    double ans {};
    p[0] = 1;
    p1[0] = 1;
    for( int i = 1; i <= n; ++ i ){
      p[i] = p[i - 1] * burger;
      p1[i] = p1[i - 1] * (1 - burger);
    }
    for( int i = 2; i <= n + 1; ++ i ){
      cerr << "doing " << pascal[n][i] << " * " << p[i - 1] << " * " << p1[n + 1 - i] << " = " << pascal[n][i] * p[i - 1] * p1[n + 1 - i] << endl;
      ans += pascal[n][i] * p[i - 1] * p1[n + 1 - i];
    }
    cout << setprecision(6) << fixed << ans << '\n';
  }
  return 0;
}
