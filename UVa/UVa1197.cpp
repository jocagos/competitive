#include <cstdio>

using namespace std;
constexpr int MAXN = 30030;

int parent[MAXN] {}, rank[MAXN] {}, set_size[MAXN] {};
int num_sets = MAXN;

void init( int n ){
  num_sets = n;
  for( int i = 0; i < num_sets; ++ i ){
    parent[i] = i;
    rank[i] = set_size[i] = 1;
  }
}

inline int find_set( int i ){
  return parent[i] == i ? i : parent[i] = find_set( parent[i] );
}

inline bool is_same_set( int i, int j ){
  return find_set( i ) == find_set( j );
}

inline bool union_set( int i, int j ){
  int x = find_set( i ), y = find_set( j );
  if( x != y ){
    -- num_sets;
    if( rank[x] > rank[y] ){
      parent[y] = x;
      set_size[x] += set_size[y];
    }
    else{
      parent[x] = y;
      set_size[y] += set_size[x];
      if( rank[x] == rank[y] ) ++ rank[y];
    }
    return true;
  }
  return false;
}

inline int size_of_set( int i ){
  return set_size[find_set( i )];
}

int main(){
  int n {}, m {}, k {}, a {}, b {};
  while( scanf("%d %d", &n, &m), n | m ){
    init( n );
    for( int i = 0; i < m; ++ i ){
      scanf("%d", &k);
      scanf("%d", &a);
      while( -- k ){
	scanf("%d", &b);
	union_set( a, b );
      }
    }
    printf("%d\n", size_of_set( 0 ) );
  }
  return 0;
}
