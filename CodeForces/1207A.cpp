#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t {};
  cin >> t;
  while( t -- ){
    int b {}, p {}, f {}, h {}, c {};
    cin >> b >> p >> f;
    cin >> h >> c;
    int profit {};
    if( c > h ) swap( p, f ), swap( h, c );
    while( b >= 2 ){
      if( p ) b -= 2, p --, profit += h;
      else if( f ) b -= 2, f --, profit += c;
      else break;
    }
    cout << profit << endl;
  }
  return 0;
}
