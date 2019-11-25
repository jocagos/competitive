#include <bits/stdc++.h>
constexpr int MAXN = 10100;
using namespace std;
using CarMaker = tuple<int, int, string>;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  string line;
  vector<CarMaker> inters(MAXN);
  getline( cin, line );
  t = stoi( line );
  while( t -- ){
    int d, q, nquery;
    getline( cin, line );
    d = stoi( line );
    string s;
    int l, r;
    for( int i = 0; i < d; ++i ){
      getline( cin, line );
      istringstream iss( line );
      iss >> s >> l >> r;
      inters[i] = { l, r, s };
    }
    getline( cin, line );
    q = stoi( line );
    sort( inters.begin(), inters.begin() + d, []( CarMaker& lhs, CarMaker& rhs ) -> bool {
						if( get<0>( lhs ) != get<0>( rhs ) ) return get<0>( lhs ) < get<0>( rhs );
						else if( get<1>( lhs ) != get<1>( rhs ) ) return get<1>( lhs ) < get<1>( rhs );
						else return get<2>( lhs) < get<2>( rhs );
					      } );
    
    while( q -- ){
      int count = 0, index = 0;
      index = 0;
      getline( cin, line );
      nquery = stoi( line );
      int i = 0;
      while( i < d and get<0>( inters[i] ) > nquery ) ++ i;
      while( i < d ){
	if( count > 1 ) break;
	if( get<0>( inters[i] ) <= nquery and nquery <= get<1>( inters[i] ) )
	  ++ count, index = i;
	if( get<0>( inters[i] ) > nquery ) break;
	++ i;
      }
      if( count == 1 ) cout << get<2>( inters[index] ) << endl;
      else cout << "UNDETERMINED" << endl;
    }
    if( t ) cout << endl;
  }
  return 0;
}
