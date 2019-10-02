#include <iostream>
#include <cmath>

constexpr int MAXN = 110;
using namespace std;

long long a[MAXN] {};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q {};
  cin >> q;
  while( q -- ){
    int n {};
    cin >> n;
    for( int i = 0; i < n; ++ i ) cin >> a[i];
    long long s = 0;
    for( int i = 0; i < n; ++ i ) s += a[i];
    s = ceil( 1. * s / n );
    cout << s << '\n';
  }
  return 0;
}
