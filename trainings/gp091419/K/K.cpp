#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
constexpr int MAXN = 100100;
using namespace std;

vector<int> a( MAXN );

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, k {}, t {};
  cin >> n >> k >> t;
  for( int _ = 0; _ < n; ++ _ ){
    cin >> a[i];
    a[i] = ceil( 1. * a[i] / t );
  }
  auto mx_it = max_element( begin( a ), begin( a ) + n );
  bool able = true;
  while( able ){
    int rem{k}, val{}, idx{};
    while( rem -- ){
      int threshold{*mx_it};
      while( threshold > 0 and idx >= n ){
	threshold -= a[i];
	if( threshold >= 0 ) idx ++;	
      }
    }
  }
  return 0;
}
