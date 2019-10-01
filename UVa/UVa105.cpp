#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 10010;

vector<int> vals( MAXN, 0 );

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int l {}, r {}, h {};
  while( cin >> l >> h >> r )
    for( int i = l; i < r; ++ i )
      vals[i] = max( vals[i], h );
  int m {};
  bool first {true};
  for( int i = 1; i <= 10000; ++ i ){
    if( vals[i] != m ){
      cout << ( first ? "" : " " ) << i << " " << vals[i];
      first = false;
      m = vals[i];
    }
  }
  cout << endl;
  return 0;
}
