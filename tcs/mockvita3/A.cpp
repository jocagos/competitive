#include <bits/stdc++.h>

using namespace std;
int x, y, d;

int main(){
  int tc {};
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> tc;
  while( tc -- ){
    cin >> x >> y;
    int _x{x}, _y{y};
    d = __gcd( _x, _y );
    cout << d << '\n';
  }
  return 0;
}
