#include <bits/stdc++.h>
constexpr int MAXN = 1e6 + 100;
using namespace std;
using pii = pair<int, int>;

pair<pii, pii> intersect( pii a, pii b, pii c, pii d ){
  int left { max( min( a.first, b.first ), min( c.first, d.first ) ) },
      right { min( max( a.first, b.first ), max( c.first, d.first ) ) },
      up { min( max( a.second, b.second ), max( c.second, d.second ) ) },
      down { max( min( a.second, b.second ), min( c.second, d.second ) ) };
  if( right <= left or up <= down ) return { { 0, 0 }, { 0, 0 } };
  return { { left, down }, { right, up } };
}

long long square( pii a, pii b ){
  return 1LL * abs( a.first - b.first ) * abs( a.second - b.second );
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<pii> p(6);
  for( int i = 0; i < 6; ++ i )
    cin >> p[i].first >> p[i].second;
  auto wb1 = intersect( p[0], p[1], p[2], p[3] );
  auto wb2 = intersect( p[0], p[1], p[4], p[5] );
  auto inter = intersect( wb1.first, wb1.second, wb2.first, wb2.second );
  long long white_square = square( p[0], p[1] );
  long long white_black1 = square( wb1.first, wb1.second );
  long long white_black2 = square( wb2.first, wb2.second );
  long long square_inter = square( inter.first, inter.second );
  if( white_square > white_black1 + white_black2 - square_inter )
    cout << "YES\n";
  else cout << "NO\n";
  return 0;
}
