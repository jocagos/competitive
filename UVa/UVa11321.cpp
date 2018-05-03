#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int m;

int main(){
  int n;
  auto f = [](long left, long right) -> bool {
    if( left % m != right % m ) return left % m < right % m;
    else if( left % 2 == 0 and right % 2 == 0 ) return left < right;
    else if( left % 2 and right % 2 == 0 ) return true;
    else if( right % 2 and left % 2 == 0 ) return false;
    else if( left % 2 and right % 2 ) return left > right;
  };
  vector<long> vals;
  while( scanf("%d %d", &n, &m), n|m ){
    long t;
    for( int i = 0; i < n; ++i ){
      scanf("%ld", &t);
      vals.emplace_back(t);
    }
    sort( vals.begin(), vals.end(), f );
    cout << n << " " << m << endl;
    for( auto& x : vals ) cout << x << endl;
    vals.clear();
  }
  cout << n << " " << m << endl;
  return 0;
}
