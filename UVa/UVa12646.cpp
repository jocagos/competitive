#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int a, b, c;
  while( cin >> a >> b >> c ){
    if( a != b and a != c )
      cout << "A\n";
    else if( b != a and b != c )
      cout << "B\n";
    else if( c != a and c != b )
      cout << "C\n";
    else
      cout << "*\n";
  }
  return 0;
}
