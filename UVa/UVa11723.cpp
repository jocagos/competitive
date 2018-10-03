#include <iostream>

using namespace std;

int main(){
  int n, r, i = 0;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while( cin >> n >> r, n | r ){
    cout << "Case " << ++i << ": ";
    if( n / r > 26 ) cout << "impossible\n";
    else if( n % r == 0 ) cout << n / r - 1 <<"\n";
    else cout << n / r << "\n";
  }
  return 0;
}
