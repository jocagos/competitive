#include <iostream>
#include <set>

using namespace std;

set<int> exps { 2, 3, 5, 7, 13, 17, 19, 31, 61, 89, 107, 127, 521, 607, 1279 };

int main(){
  int a, b;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while( cin >> a ){
    cin >> b;
    if( exps.find( a + b ) == exps.end() ) cout << "2^" << (a + b) << "-1 not prime\n";
    else cout << "2^" << (a + b) << "-1 is prime\n";
  }
  return 0;
}
