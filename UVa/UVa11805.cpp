#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for( int _ = 1; _ <= t; ++ _ ){
    int n, k, p;
    cin >> n >> k >> p;
    int ans = (k + p) % n;
    cout << "Case " << _ << ": " << ( ans ? ans : ans + n ) << '\n';
  }
  return 0;
}
