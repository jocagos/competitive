#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
constexpr int MAXN = 1e4, MAXK = 1e4 + 100;
vector<string> vs( MAXN );
vector<int> periods( MAXN );

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {}, n {}, k {}, g {};
  cin >> tc;
  while( tc -- ){
    cin >> n >> k;
    for( int i = 0; i < n; ++ i )
      cin >> vs[i] >> periods[i];
    if( n > 1 )
      for( int i = 1; i < n; ++ i )
	g = __gcd( periods[i - 1], periods[i] );
    else
      g = periods[0];
    for( int i = 0; k > 0; i += g ){
      if( i == 0 ) continue;
      for( int j = 0; j < n; ++ j ){
	if( i % periods[j] == 0 ){
	  cout << i << " " << vs[i] << '\n';
	  -- k;
	}
      }
    }
  }
  return 0;
}
