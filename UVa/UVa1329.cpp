#include <cstdio>
#include <cmath>

using namespace std;
constexpr int MAXN = 34567;
int pa[MAXN] {}, dist[MAXN] {};

inline void init( int n ){
  for( int i = 1; i <= n; ++ i ){
    pa[i] = i; 
    dist[i] = 0;
  }
}

inline int find_set( int i ){
  if( pa[i] == i )
    return i;
  int p = find_set( pa[i] );
  dist[i] += dist[pa[i]];
  return pa[i] = p;
}

int main(){
  int tc {};
  scanf("%d", &tc);
  while( tc -- ){
    int n {}, a {}, b {};
    scanf("%d", &n);
    init( n );
    char buf[5] {};
    while( scanf("%s", buf), buf[0] != 'O' ){
      if( buf[0] == 'E' ){
	scanf("%d", &a);
	find_set( a );
	printf("%d\n", dist[a]);
      }
      else if( buf[0] == 'I' ){
	scanf("%d %d", &a, &b);
	pa[a] = b;
	dist[a] = abs( a - b ) % 1000;
      }
    } // end while
  }
  return 0;
}
