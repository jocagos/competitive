/* 
 * Rank 31!!!
 * I just tried to simulate the multiset instead of using one
 * Jose Luis Gallegos Cardenas
 */
#include <iostream>
#include <set>
#include <cstring>

using namespace std;
constexpr int MAXN = 1001000;

int main(){
  int n;
  while( scanf("%d", &n), n ){
    int cnt[MAXN] {};
    set<long long> hoax;
    long long sum = 0, tmp, t;
    for( int day = 0; day < n; ++ day ){
      scanf("%lld", &tmp);
      for( int j = 0; j < tmp; ++ j ){
	scanf("%lld", &t);
	++ cnt[t];
	if( cnt[t] == 1 )
	  hoax.insert(t);
      }
      long long ith = *(--hoax.end());
      long long itl = *(hoax.begin());
      sum += ith - itl;
      -- cnt[itl];
      -- cnt[ith];
      if( cnt[itl] == 0 )
	hoax.erase(itl);
      if( cnt[ith] == 0 )
	hoax.erase(ith);
    }
    printf("%lld\n", sum);
  }
  return 0;
}
