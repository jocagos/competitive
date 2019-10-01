#include <bits/stdc++.h>
constexpr int MAXN = 1010;
using namespace std;
vector<tuple<int, int>> a( MAXN );

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, tmp {};
  cin >> n;
  for( int i = 1; i <= n; ++ i ){
    cin >> tmp;
    a[i - 1] = { tmp, i };
  }
  sort( begin( a ), begin( a ) + n, []( tuple<int, int>& lhs, tuple<int, int>& rhs ) -> bool {
				if( get<0>( lhs ) != get<0>( rhs ) ) return get<0>( lhs ) > get<0>( rhs );
				else return get<1>( lhs ) < get<1>( rhs );
			      }
    );
  long long c {}, s {};
  for( int i = 0; i < n; ++ i ){
    s += c * get<0>( a[i] ) + 1;
    c ++;
  }
  cout << s << endl;
  for( int i = 0; i < n; ++ i ) cout << get<1>( a[i] ) << (i + 1 == n ? "\n" : " ");
  return 0;
}
