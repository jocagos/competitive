#include <iostream>
#include <cstring>
using namespace std;

int main(){
  int m, n;
  while( scanf("%d %d ", &n, &m), m || n ){
    int l, r, _min = 1000000, _max = 0;
    bool t[1000001];
    memset(t, 0, sizeof t);
    for( int i = 0; i < n; ++i ){
      scanf("%d %d ", &l, &r);
      if( l < _min ) _min = l;
      if( r > _max ) _max = r;
      for( int j = l; j < r; ++j ) t[j]^=true;
    }
    for( int i = 0; i < m; ++i ){
    }
  }
  return 0;
}
