#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

inline int abs( int x ){
  if( x >= 0 )
    return x;
  else
    return -x;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int a {}, b {}, c {}, d {};
  vector<pair<int, int>> points;
  cin >> a >> b >> c >> d;
  points.emplace_back( a, b );
  points.emplace_back( c, d );
  points.emplace_back( a, d );
  points.emplace_back( c, b );
  sort( points.begin(), points.end() );
  pair<int, int> L1 = points[0], L2 = points[3];
  cin >> a >> b >> c >> d;
  points[0] = { a, b };
  points[1] = { c, d };
  points[2] = { a, d };
  points[3] = { c, b };
  sort( points.begin(), points.end() );
  pair<int, int> R1 = points[0], R2 = points[3];
  int AL = abs( L2.first - L1.first ) * abs( L2.second - L1.second );
  int AR = abs( R2.first - R1.first ) * abs( R2.second - R1.second );
  pair<int, int> IL( max( L1.first, R1.first ), max( L1.second, R1.second ) ),
    IR( min( L2.first, R2.first ), min( L2.second, R2.second ) );
  if( IL.first > IR.first ) // no intersection
    cout << AL + AR << '\n';
  else
    cout << (AL + AR - abs( IR.first - IL.first ) * abs( IR.second - IL.second )) << '\n';
  return 0;
}
