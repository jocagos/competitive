#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // atkin();
  int a {}, b {}, n {};
  cin >> a >> b;
  cin >> n;
  set<int> common {};
  for( int i = 1; i <= max( ceil( sqrt( a ) ), ceil( sqrt( b ) ) ); ++ i ){
    if( a % i == 0 and b % i == 0 )
      common.emplace( i );
    if( b % (a/i) == 0 and a % (a/i) == 0 )
      common.emplace( a / i );
    if( a % (b/i) == 0 and b % (b/i) == 0 )
      common.emplace( b / i );
  }
  vector<int> divs( common.begin(), common.end() );
  for( auto& d : divs ) d *= -1;
  reverse( divs.begin(), divs.end() );
  for( auto& p : divs ) cerr << p << " ";
  cerr << endl;
  while( n -- ){
    int left {}, right {};
    cin >> left >> right;
    left = -left;
    right = -right;
    auto pos = lower_bound( divs.begin(), divs.end(), right );
    if( pos != end( divs ) ){
      if( -left <= -(*pos) and -(*pos) <= -right )
	cout << -(*pos) << endl;
      else cout << "-1\n";
    }
    else cout << "-1\n";
    
  }
  return 0;
}
