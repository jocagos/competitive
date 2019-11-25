#include <bits/stdc++.h>

using namespace std;

int main(){
  int n = 9, r = 3;
  vector<int> a( n, 1 );
  for( int i = 0; i < n; ++ i ) a[i] += i;
  using iii = tuple<int, int, int>;
  using iiix3 = tuple<iii, iii, iii>;
  set<iiix3> tps;
  do{
    iii tmp;
    vector<iii> b;
    for( int i = 0; i < n / r; ++ i ){
      vector<int> c( r, 0 );
      for( int j = 0; j < r; ++ j )
	c[j] = a[i * r + j];
      sort( begin( c ), end( c ) );
      get<0>( tmp ) = c[0];
      get<1>( tmp ) = c[1];
      get<2>( tmp ) = c[2];
      b.emplace_back( tmp );
    }
    sort( begin( b ), end( b ) );
    iiix3 lmao = {b[0], b[1], b[2]};
    tps.emplace( lmao );
  } while( next_permutation( begin( a ), end( a ) ) );
  cout << "there are " << tps.size() << " different sets with n = " << n << " and r = " << r << endl;
  for( auto perm : tps ){
    cout << "{ { " << get<0>(get<0>(perm)) << ", " << get<1>(get<0>(perm)) << "," << get<2>(get<0>(perm)) << " }, { " << get<0>(get<1>(perm)) << ", " << get<1>(get<1>(perm)) << ", " << get<2>(get<1>(perm)) << " }, { " << get<2>(get<0>(perm)) << ", " << get<2>(get<1>(perm)) << ", " << get<2>(get<2>( perm ) ) << " } }\n";
  }
  return 0;
}
