#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 100010;

int main(void){
  int tc;
  // fastio;
  // cin >> tc;
  scanf("%d", &tc);
  vector<int> v( MAXN );
  while( tc -- ){
    int n;
    // cin >> n;
    scanf("%d", &n);
    for( int i = 0; i < n; ++ i )
      scanf("%d", &v[i]);// cin >> v[i]
    int ma = INT_MIN, diff = INT_MIN;
    for( int i = 0; i < n - 1; ++ i ){
      if( v[i] > ma ) ma = v[i];
      if( ma - v[i + 1] > diff ) diff = ma - v[i + 1];
    }
    // cout << diff << '\n';
    printf("%d\n", diff);
  }
  return 0;
}
