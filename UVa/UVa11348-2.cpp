// You don't need `unordered_map` if you know how to make
// an implicit hash table/hash map with arrays
// and your approach allows it
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;
constexpr int MAXN = 52;
constexpr int MAXA = 10010;
int stamps[MAXN][MAXN] {};
int freqs[MAXA] {};
int prev[MAXA] {};

int main(){
  int tc {}, n {}, m {};
  scanf("%d", &tc);
  for( int CASE = 1; CASE <= tc; ++ CASE ){
    memset( freqs, 0, sizeof freqs );
    memset( prev, 0, sizeof prev );
    scanf("%d", &n);
    for( int person = 1; person <= n; ++ person ){
      scanf("%d", &m);
      stamps[person][0] = m;
      for( int i = 1; i <= m; ++ i ){
	scanf("%d", &stamps[person][i]);
	if( prev[ stamps[person][i] ] != person ){
	  ++ freqs[ stamps[person][i] ];
	  prev[ stamps[person][i] ] = person;
	}
      }
    }
    int unique {}, my_stamps {};
    for( int i = 0; i < MAXA; ++ i )
      if( freqs[i] == 1 ) // unique stamp
	++ unique;
    printf("Case %d:", CASE);
    if( unique == 0 ){
      printf(" \n");
      continue;
    }
    memset( prev, 0, sizeof prev );
    for( int person = 1; person <= n; ++ person ){
      my_stamps = 0;
      m = stamps[person][0];
      for( int i = 1; i <= m; ++ i ){
	if( prev[ stamps[person][i] ] == person )
	  continue;
	if( freqs[ stamps[person][i] ] == 1 ){
	  ++ my_stamps;
	  prev[ stamps[person][i] ] = person;
	}
      }
      double ans = my_stamps * 100.0 / unique;
      printf(" %.6lf%%", ans);
    }
    printf("\n");
  }
  return 0;
}
