#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int m;

int main(){
  int n;
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  auto f = [](long left, long right) -> bool {
    int first = (left % m) - (right % m);
    if( first ) return first < 0;
    else{
      int _l = left & 1, _r = right & 1;
      int sum = _r + _l;
      if( sum == 1 ) return _l & 1 == 1;
      else if( sum == 2 ) return !(left < right);
      else if( sum == 0 ) return left < right;
    }
  };
  long vals[10005];
  while( cin >> n >> m ){
    if( n == 0 ) break;
    for( int i = 0; i < n; ++ i ) cin >> vals[i];
    sort( vals, vals + n, f );
    cout << n << " " << m << endl;
    for( int i = 0; i < n; ++ i ) cout << vals[i] << endl;
  }
  cout << n << " " << m << endl;
  return 0;
}
