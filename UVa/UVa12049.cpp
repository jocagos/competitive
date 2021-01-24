#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;

int main(){
  int tc {}, n {}, m {}, tmp {};
  scanf("%d", &tc);
  while( tc -- ){
    scanf("%d %d", &n, &m);
    unordered_map<int, int> lhs, rhs, used;
    for( int i = 0; i < n; ++ i ){
      scanf("%d", &tmp);
      lhs[tmp] ++;
    }
    for( int i = 0; i < m; ++ i ){
      scanf("%d", &tmp);
      rhs[tmp] ++;
    }
    int ans {};
    for( auto& it : lhs ){
      auto& key = it.first;
      ans += abs( lhs[key] - rhs[key] );
      used[key] ++;
    }
    for( auto& it : rhs ){
      auto& key = it.first;
      if( not used[key] )
	ans += abs( lhs[key] - rhs[key] );
    }
    printf("%d\n", ans);
  }
  return 0;
}
