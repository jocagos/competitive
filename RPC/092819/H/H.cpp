#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 1e6 + 100, MAXQ = 110;
vector<int> a {};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, q {}, tmp {};
  cin >> n >> q;
  for( int i = 0; i < n; ++ i ) cin >> a[i];
  sort( begin( a ), begin( a ) + n );
  int query {};
  while( q -- ){
    cin >> query;
    auto it = a.find( query );
    if( it != a.end() and *it == query ){
      
    }
    else if( it != a.end() and *it > query ){
    }
  }
  return 0;
}
