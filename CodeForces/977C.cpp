#include <iostream>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;

int main(){
  int n, tmp, k;
  scanf("%d %d", &n, &k);
  map<int, int> values;
  for( int i = 0; i < n; ++i ){
    scanf("%d", &tmp);
    values[tmp]++;
  }
  if( k == 0 ){
    cout << (values.begin()->first - 1 >= 1 ? values.begin()->first - 1 : -1) << endl;
    exit(0);
  }
  for( auto x : values ){
    k -= x.second;
    if( k == 0 ){ cout << x.first << endl; break; }
    else if( k < 0 ){ cout << -1 << endl; break; }
  }
  return 0;
}
