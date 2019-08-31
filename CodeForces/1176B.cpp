#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 110;
vector<int> a( MAXN ), m( MAXN );

int main(){
  int q, n, t;
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> q;
  while( q -- ){
    cin >> n;
    for( int i = 0; i < n; ++ i ) cin >> a[i];
    for( int i = 0; i < n; ++ i ) a[i] %= 3;
    int midx = 0;
    int c = 0;
    for( int i = 0; i < n; ++ i )
      if( a[i] % 3 ) m[midx ++] = a[i];
    found = midx > 0;
    while( found ){
      c += n - midx;
      sort( m.begin(), m.begin() + midx );
      set<int> tmp;
      for( int i = 0; i < midx; ++ i ){
	auto it = lower_bound( m.begin(), m.begin()  + midx, 3 - m[i] );
	if( *it == 3 - m[i] ){
	  tmp.emplace( i );
	  tmp.emplace( it - m.begin() );
	}
      }
    }
    
  }
  return 0;
}
