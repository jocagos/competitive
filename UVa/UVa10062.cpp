#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>

using namespace std;
constexpr int MAXC = 256;
vector<tuple<int, int>> ans( MAXC );

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string line {};
  bool first = true;
  while( getline( cin, line ) ){
    if( first )
      first = false;
    else
      cout << '\n';
    int vals[MAXC] {};
    for( auto& c : line )
      ++ vals[c];
    int idx {};
    for( int i = 0; i < MAXC; ++ i )
      if( vals[i] )
	ans[idx ++] = make_tuple( vals[i], i );
    sort( ans.begin(), ans.begin() + idx,
	  []( tuple<int, int>& lhs, tuple<int, int>& rhs ) -> bool{
	    if( get<0>( lhs ) != get<0>( rhs ) )
	      return get<0>( lhs ) < get<0>( rhs );
	    else
	      return get<1>( lhs ) > get<1>( rhs );
	  }
	  );
    for( int i = 0; i < idx; ++ i )
      cout << get<1>( ans[i] ) << " " << get<0>( ans[i] ) << '\n';
  }
  return 0;
}
