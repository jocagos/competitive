#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 55;

int main(){
  int TC {};
  cin >> TC;
  vector<int> vals( MAXN );
  for( int CASE = 1; CASE <= TC; ++ CASE ){
    int n {};
    cin >> n;
    for( int i = 0; i < n; ++ i )
      cin >> vals[i];
    if( n == 1 )
      cout << vals[0];
    else if( n == 2 )
      cout << max(vals[0], vals[1]);
    else{
      long long lhs {}, rhs {};
      for( int i = 0; i < n; ++ i ){
	if( i % 2 ) rhs += vals[i];
	else lhs += vals[i];
      }
      cout << max(lhs, rhs);
    }
    cout << '\n';
  }
  return 0;
}
