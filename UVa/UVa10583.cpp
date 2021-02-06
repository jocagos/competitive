#include <cstdio>

using namespace std;
/*
 * UnionFind DisjointSets - C++11
 * With Path Compressing and Union by Rank
 * @zagerer
 */

constexpr int MAXSIZE = 1000001;
int pa[MAXSIZE], ra[MAXSIZE], set_size[MAXSIZE];
int num_sets = MAXSIZE;

inline void init( int n, int idx = 0 ){
  num_sets = n + idx;
  for( int i = 0; i < num_sets; ++ i ){
    pa[i] = i;
    ra[i] = set_size[i] = 1;
  }
}

inline int find_set( int i ){
  return pa[i] == i ? i : pa[i] = find_set( pa[i] );
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
    }
    else{
      pa[x] = y;
      set_size[y] += set_size[x];
      if( ra[x] == ra[y] ) ra[y] ++;
    }
    return true;
  }
  return false;
}

inline int size_of_set( int i ){
  return set_size[find_set( i )];
}

int main(){
  int m {}, n {};
  int CASE = 1;
  while( scanf("%d %d", &n, &m), n | m ){
    int lhs {}, rhs {};
    init( n );
    for( int i = 0; i < m; ++ i ){
      scanf("%d %d", &lhs, &rhs);
      union_set( lhs - 1, rhs - 1 );
    }
    printf("Case %d: %d\n", CASE, num_sets);
    ++ CASE;
  }
  return 0;
}
