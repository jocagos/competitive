#include <iostream>
#include <cmath>
#include <iomanip>
#define EPS 1e-6

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for( int i = 1; i <= t; ++ i ){
    double d, u, v;
    cin >> d >> v >> u;
    if( u == 0 or v == 0 or abs(u - v) < EPS or v > u ) cout << "Case " << i << ": can't determine\n";
    else cout << "Case " << i << ": " << setprecision(3) << fixed << abs( d / u - d / sqrt( u * u - v * v ) ) << "\n";
  }
  return 0;
}
