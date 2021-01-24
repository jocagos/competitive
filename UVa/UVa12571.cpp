#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
constexpr int MAXN = 100100, MAXQ = 232;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  vector<long> s( MAXN ), queries( MAXQ, 0 );
  while( tc -- ){
    for( int i = 0; i < MAXQ; ++ i )
      queries[i] = 0;
    long tmp {}, m {};
    int n {}, q {};
    cin >> n >> q;
    for( int i = 0; i < n; ++ i ){
      cin >> s[i];
      for( int k = 0; k <= 230; ++ k )
	queries[k] = max( queries[k], k & s[i] );
    }
    while( q -- ){
      cin >> tmp;
      cout << queries[tmp] << '\n';
    }
  }
  return 0;
}
