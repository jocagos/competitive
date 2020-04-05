#include <iostream>
#include <algorithm>
#include <utility>
#include <functional>
#include <tuple>
#include <vector>

using namespace std;
constexpr int MAX_TIME = 60 * 24;

int main(){
  int tc {};
  cin >> tc;
  for( int CASE = 1; CASE <= tc; ++ CASE ){
    int n {};
    cin >> n;
    vector<tuple<int, int, int>> pairs;
    string ans( n, 'C' );
    for( int i = 0; i < n; ++ i ){
      int left {}, right {};
      cin >> left >> right;
      pairs.emplace_back( left, right, i );
    }
    sort( begin( pairs ), end( pairs ) );
    vector<tuple<int, int, int>> C {}, J {};
    bool able = true;
    for( int i = 0; i < n and able; ++ i ){
      auto tup = pairs[i];
      if( C.size() == 0 )
	C.push_back( tup );
      else if( get<1>( C.back() ) <= get<0>( tup ) )
	C.push_back( tup );
      else if( J.size() == 0 )
	J.push_back( tup );
      else if( get<1>( J.back() ) <= get<0>( tup ) )
	J.push_back( tup );
      else{
	ans = "IMPOSSIBLE";
	able = false;
	break;
      }
    }
    if( able ){
      for( auto x : C )
	ans[get<2>( x )] = 'C';
      for( auto x : J )
	ans[get<2>( x )] = 'J';
    }
    cout << "Case #" << CASE << ": " << ans << endl;
  }
  return 0;
}
