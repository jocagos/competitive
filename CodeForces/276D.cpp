#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  unsigned long long a, b;
  cin >> a >> b;
  int n = sizeof(unsigned long long) * 8 - __builtin_clzll( a ^ b );
  unsigned long long ans {};
  for( int i = 0; i < n; ++ i )
    ans = ans << 1 | 1;
  if( a == b ) cout << "0\n";
  else cout << ans << endl;
  return 0;
}
