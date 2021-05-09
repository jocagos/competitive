#include <cstdio>
#include <algorithm>

using namespace std;
constexpr int MAXN = 55;

int main(){
  int n {};
  int me[MAXN] {}, lira[MAXN] {};
  scanf("%d", &n);
  for( int i = 0; i < n; ++ i )
    scanf("%d", &me[i]);
  for( int i = 0; i < n; ++ i )
    scanf("%d", &lira[i]);
  sort( me, me + n );
  sort( lira, lira + n );
  int cnt {}, pos_lira {n-1};
  for( int i = n - 1; i >= 0 and pos_lira >= 0; -- i ){
    while( pos_lira >= 0 ){
      if( lira[pos_lira] < me[i] ){
	cnt += me[i];
	-- pos_lira;
	break;
      }
      -- pos_lira;
    }
  }
  printf("%d\n", cnt);
  return 0;
}
