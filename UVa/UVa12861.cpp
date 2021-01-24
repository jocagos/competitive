#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
constexpr int MAXN = 1010;
vector<int> a( MAXN );

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  while( cin >> n ){
    for( int i = 0; i < n; ++ i )
      cin >> a[i];
    sort( a.begin(), a.begin() + n );
    long ans_L {}, ans_R = min( abs( a[0] - a[n - 1] ), 24 - abs( a[0] - a[n - 1] ) );
    for( int i = 0; i < n - 1; i += 2 ){
      int A = abs( a[i] - a[i + 1] );
      ans_L += min( 24 - A, A );
    }
    for( int i = 1; i < n - 2; i += 2 ){
      int A = abs( a[i] - a[i + 1] );
      ans_R += min( 24 - A, A );
    }
    cout << min( ans_L, ans_R ) << '\n';
  }
  return 0;
}
