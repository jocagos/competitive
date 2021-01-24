#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <tuple>
#include <functional>

using namespace std;
template <typename T>
inline T LSOne( T S ){
  return ((S) & -(S));
}
constexpr int MAXN = 5, MAXM = 105;
constexpr int VAL[] = {1, -1, 2, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 4, -1, -1, -1, -1, -1, -1 };

vector<int> ft(MAXN, 0);

inline void reset(){
  ft.assign(MAXN, 0 );
}

inline int rsq( int i ){
  int sum {};
  while( i ){
    sum += ft[i];
    i -= LSOne(i);
  }
  return sum;
}

inline int rsq( int i, int j ){
  return rsq(j) - rsq(i - 1);
}

inline void update( int i, int v ){
  while( i < (int)ft.size() ){
    ft[i] += v;
    i += LSOne(i);
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {}, m {}, n {};
  string str {};
  vector<tuple<int, int, string>> vs( MAXM );
  cin >> tc;
  while( tc -- ){
    cin >> n >> m;
    for( int i = 0; i < m; ++ i ){
      cin >> str;
      // process each string, get their inversion count
      reset();
      int inversions {};
      for( int idx = (int)str.length() - 1; idx >= 0; -- idx ){
	int I = VAL[str[idx] - 'A'];
	
	inversions += rsq( I - 1 );
	update( I, 1 );
      }
      vs[i] = make_tuple( inversions, i, str );
    }
    sort( vs.begin(), vs.begin() + m,
	  []( tuple<int, int, string>& lhs, tuple<int, int, string>& rhs ) -> bool{
	    if( get<0>( lhs ) != get<0>( rhs ) )
	      return get<0>( lhs ) < get<0>( rhs );
	    else if( get<1>( lhs ) != get<1>( rhs ) )
	      return get<1>( lhs ) < get<1>( rhs );
	    else
	      return get<2>( lhs ) < get<2>( rhs );
	  } );
    for( int i = 0; i < m; ++ i )
      cout << get<2>( vs[i] ) << '\n';
    // for( int i = 0; i < m; ++ i ){
    //   cerr << "vs[" << i << "] = " << get<2>( vs[i] ) << '\t'
    // 	   << "inv: " << get<0>( vs[i] ) << endl;
    // }
    if( tc )
      cout << '\n';
  }
  return 0;
}
