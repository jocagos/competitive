#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
  int n, m;
  scanf("%d %d", &n, &m);
  int * vals = new int[m];
  memset(vals, 0, sizeof(vals));
  for( int i = 0; i < m; ++i ) scanf("%d", &vals[i]);
  sort(vals, vals+m);
  if( m == n ){ cout << vals[m-1] - vals[0] << endl; return 0; }
  int diff = vals[n-1] - vals[0], window;
  for( int i = 1; i < m-n+1; ++i ){
    window = vals[n-1+i] - vals[i];
    if( window < diff ) diff = window;
  }
  cout << diff << endl;
  free(vals);
  return 0;
}
