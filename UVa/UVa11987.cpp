#include <cstdio>
/*
 * UnionFind DisjointSets - C++11
 * With Path Compressing
 * @zagerer
 */
using namespace std;

constexpr int MAXSIZE = 200020;
int pa[MAXSIZE], ra[MAXSIZE], set_size[MAXSIZE];
long long set_sum[MAXSIZE];

inline void init( int n, int idx = 1 ){
  for( int i = 0; i <= n; ++ i ){
    pa[i] = ra[i] = i;
    set_size[i] = 1;
    set_sum[i] = 0;
  }
}

inline int find_set( int i ){
  return i == pa[i] ? i : pa[i] = find_set( pa[i] );
}

inline bool is_same_set( int i, int j ){
  return find_set( i ) == find_set( j );
}

inline bool union_set( int i, int j ){
  int pa_i = find_set( i ), pa_j = find_set( j );
  if( pa_i != pa_j ){
    set_sum[pa_i] += set_sum[pa_j];
    set_size[pa_i] += set_size[pa_j];
    set_sum[pa_j] = set_size[pa_j] = 0;
    pa[pa_j] = pa_i;
    return true;
  }
  return false;
}

inline int size_of_set( int i ){
  return set_size[find_set( ra[i] )];
}

inline long long int sum_of( int i ){
  return set_sum[find_set( ra[i] )];
}

int main(){
  int n {}, m {};
  while( scanf("%d %d", &n, &m) == 2 ){
    int q {}, a {}, b {};
    init( n + m );
    for( int i = 0; i <= n; ++ i )
      set_sum[i] = i;
    for( int i = 0; i < m; ++ i ){
      scanf("%d", &q);
      if( q == 1 ){
	scanf("%d %d", &a, &b);
	union_set( find_set( ra[a] ), find_set( ra[b] ) );
      }
      else if( q == 2 ){
	scanf("%d %d", &a, &b);
	int x = find_set( ra[a] ), y = find_set( ra[b] );
	if( x != y ){
	  set_sum[x] -= a;
	  -- set_size[x];
	  ra[a] = ++ n;
	  set_sum[ra[a]] = a;
	  set_size[ra[a]] = 1;
	  union_set( find_set( ra[a] ), find_set( ra[b] ) );
	}
      }
      else if( q == 3 ){
	scanf("%d", &a);
	printf("%d %lld\n", size_of_set( a ), sum_of( a ));
      }
    }
  }
  return 0;
}
