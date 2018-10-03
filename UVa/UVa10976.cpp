#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define abs( x ) ((x) > 0 ? (x) : (-(x)))

using namespace std;

typedef pair<int, int> ii;

int main(){
  int k;
  while( scanf("%d", &k) != EOF ){
    vector<ii> pairs;
    int x;
    for( int y = k + 1; y <= 2 * k; ++ y ){
      double v {(1.0 * y * k) / (y - k)};
      int _v {y * k / ( y - k ) };
      if( abs( v - _v ) == 0 ) pairs.emplace_back( _v, y );
    }
    sort(pairs.begin(), pairs.end(), []( const ii& l, const ii& r ) -> bool {
	if( l.first != r.first ) return l.first > r.first;
	else return l.second > r.second;
      });
    cout << pairs.size() << endl;
    for( auto x : pairs ) cout << "1/" << k << " = 1/" << x.first << " + 1/" << x.second << endl;
  }
  return 0;
}
