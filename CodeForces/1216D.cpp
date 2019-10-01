#include <bits/stdc++.h>
constexpr int MAXN = 200200;
using namespace std;

vector<long long> a( MAXN );

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  cin >> n;
  for( int i = 0; i < n; ++ i )
    cin >> a[i];
  long long mx {*max_element(begin(a), begin(a) + n)}, s {};
  for( int i = 0; i < n; ++ i ) s += a[i];
  int g = mx - a[0];
  for( int i = 1; i < n; ++ i )
    g = gcd( g, mx - a[i] );
  long long ans = (mx * 1LL * n - s) / g;
  cout << ans << ' ' << g << endl;
  return 0;
}
