#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

int f( ull l, ull m ){
  int ans = 0;
  while( l % m == 0 ){
    l /= m;
    ans++;
  }
  return ans;
}

int main(){
  int n;
  scanf("%d", &n);
  vector<ull> values(n);
  for( int i = 0; i < n; ++i ) cin >> values[i];
  auto _f = []( ull l, ull r ) -> int {
    return f( l, 2 ) - f( l, 3 ) < f( r, 2 ) - f( r, 3 );
  };
  sort( values.begin(), values.end(), _f );
  for( auto x = values.begin(); x != values.end(); x++ ) cout << *x << (x + 1 == values.end() ? "\n" : " ");
  return 0;
}
