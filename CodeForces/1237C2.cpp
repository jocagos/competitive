#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n {}, dims {3};
  cin >> n;
  vector<vector<int>> p( n, vector<int>( dims ) );
  for( int i = 0; i < n; ++ i )
    for( int j = 0; j < dims; ++ j )
      cin >> p[i][j];
  auto ans = [&]( auto& self, vector<int> ids, int k ){
	       if( k == dims ) return ids[0];
	       map<int, vector<int>> mp;
	       for( int x : ids ) mp[p[x][k]].emplace_back( x );
	       vector<int> a;
	       for( auto& q : mp ){
		 int cur = self( self, q.second, k + 1 );
		 if( cur != -1 ) a.emplace_back( cur );
	       }
	       for( unsigned i = 0; i + 1 < a.size(); i += 2 )
		 cout << a[i] + 1 << " " << a[i + 1] + 1 << "\n";
	       return (a.size() % 2 ? a.back() : -1);
	     };
  vector<int> t( n );
  iota( begin( t ), end( t ), 0 );
  ans( ans, t, 0 );
  return 0;
  return 0;
}
