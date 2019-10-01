#include <bits/stdc++.h>

using namespace std;
using quad = tuple<int, int, int, int>;
vector<quad> sols {};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for( int a = 2; a <= 200; ++ a ){
    for( int b = 2; b <= 200; ++ b ){
      for( int c = b; c <= 200; ++ c ){
	for( int d = c; d <= 200; ++ d ){
	  int ca = a * a * a, cb = b * b * b, cc = c * c * c, cd = d * d * d;
	  if( cb + cc + cd > ca ) break;
	  else if( ca == cb + cc + cd ) sols.emplace_back( a, b, c, d );
	}
      }
    }
  }
  sort( begin( sols ), end( sols ), []( quad& left, quad& right ) -> bool{
				      if( get<0>( left ) != get<0>( right ) ) return get<0>( left ) < get<0>( right );
				      else if( get<1>( left ) != get<1>( right ) ) return get<1>( left ) < get<1>( right );
				      else if( get<2>( left ) != get<2>( right ) ) return get<2>( left ) < get<2>( right );
				      else return get<3>( left ) < get<3>( right );
				    } );
  for( auto q : sols )
    cout << "Cube = " << get<0>( q ) << ", Triple = (" << get<1>( q ) << "," << get<2>( q ) << "," << get<3>( q ) << ")\n";
  return 0;
}
