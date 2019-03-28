#include <iostream>

using namespace std;

int main(){
  int n, f, a, b, c, s = 0;
  ios_base::sync_with_stdio( false );
  cin.tie( 0 );
  cout.tie( 0 );
  cin >> n;
  while( n -- ){
    cin >> f;
    s = 0;
    while( f -- ){
      cin >> a >> b >> c;
      s += a * c;
    }
    cout << s << '\n';
  }
  return 0;
}
