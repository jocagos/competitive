#include <iostream>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  map<int,int> vals;
  for( int i = 1, tmp = 0; i <= n; ++ i ){
    cin >> tmp;
    vals[tmp] = i;
  }
  if( vals.size() >= k ){
    cout << "YES" << endl;
    for( auto& x : vals ){
      if( k == 0 ) break;
      if( k-1 ) cout << x.second << " ";
      else if( k == 1 ) cout << x.second << endl;
      k--;
    }
  }
  else cout << "NO" << endl;
  return 0;
}
