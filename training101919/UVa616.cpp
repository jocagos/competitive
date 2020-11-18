#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  while( cin >> n, n ){
    bool valid {};
    for( int i = ceil(sqrt(n)); i >= 2; -- i ){
      int m {n}, j{};
      for( j = 0; j < i; ++ j ){
	if( m % i != 1 ) break;
	m = m - m / i - i;
      }
      if( j == i and m % i == 0 ){
	valid = true;
	cout << n << " coconuts, " << i << " people and 1 monkey";
	break;
      }
    }
    if( not valid ) cout << n << " coconuts, no solution";
  }
  return 0;
}
