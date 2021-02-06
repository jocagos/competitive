#include <cstdio>

using namespace std;
/*
 * UnionFind DisjointSets - C++11
 * With Path Compressing and Union by Rank
 * @zagerer
 */

constexpr int MAXSIZE = 10010;
int pa[MAXSIZE], ra[MAXSIZE], set_size[MAXSIZE], set_sum[MAXSIZE];
int num_sets = MAXSIZE;

inline void init( int n, int idx = 0 ){
  num_sets = n + idx;
  for( int i = 0; i < num_sets; ++ i ){
    pa[i] = i;
    ra[i] = set_size[i] = 1;
    set_sum[i] = 0;
  }
}

inline int find_set( int i ){
  if( pa[i] == i )
    return i;
  else{
    pa[i] = find_set( pa[i] );
    set_sum[i] = set_sum[pa[i]];
    return pa[i];
  }
}

inline bool is_same_set( int i, int j ){
  return find_set( i ) == find_set( j );
}

inline bool union_set( int i, int j ){
  if( not is_same_set( i, j ) ){
    -- num_sets;
    int x = find_set( i ), y = find_set( j );
    if( ra[x] > ra[y] ){
      pa[y] = x;
      set_size[x] += set_size[y];
      set_sum[x] += set_sum[y];
    }
    else{
      pa[x] = y;
      set_size[y] += set_size[x];
      set_sum[y] += set_sum[x];
      if( ra[x] == ra[y] ) ra[y] ++;
    }
    return true;
  }
  return false;
}

inline int size_of_set( int i ){
  return set_size[find_set( i )];
}

inline int sum_of( int i ){
  return set_sum[i];
}

int main(){
  int tc {};
  scanf("%d", &tc);
  while( tc -- ){
    int n {}, m {}, x {}, y {};
    scanf("%d %d", &n, &m);
    init( n );
    for( int i = 0; i < n; ++ i ){
      scanf("%d", &x);
      set_sum[i] = x;
    }
    for( int i = 0; i < m; ++ i ){
      scanf("%d %d", &x, &y);
      union_set( x, y );
    }
    bool able = true;
    for( int i = 0; i < n and able; ++ i )
      if( set_sum[find_set(i)] != 0 )
	able = false;
    if( able )
      printf("POSSIBLE\n");
    else
      printf("IMPOSSIBLE\n");
  }
  return 0;
}
