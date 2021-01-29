#include <cstdio>

using namespace std;
constexpr int MAXN = 1000100;
constexpr int MAXBUF = 1000;

int parent[MAXN] {}, rank[MAXN] {}, set_size[MAXN] {};
int num_sets = MAXN;

inline void init( int n ){
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
  // fprintf( stderr, "\n is the same as %d\n", '\n' );
  int tc {}, n {}, a {}, b {};
  char line[MAXBUF] {};
  fgets( line, MAXBUF, stdin );
  // fprintf( stderr, "LINE: >%s<\n", line );
  sscanf( line, "%d ", &tc );
  bool once {};
  while( tc -- ){
    int success {}, unsuccess {};
    if( not once ){
      fgets( line, MAXBUF, stdin );
      once = true;
    }
    fgets( line, MAXBUF, stdin );
    // fprintf( stderr, "LINE: >%s<\n", line );
    sscanf( line, "%d", &n );
    init( n + 1 );
    while( fgets( line, MAXBUF, stdin ), line[0] != '\n' ){
      if( feof( stdin ) ) break;
      char q {};
      sscanf( line, "%c %d %d", &q, &a, &b );
      // fprintf( stderr, "Query: (%c, %d, %d)\n", q, a, b);
      if( q == 'c' )
	union_set( a, b );
      else if( q == 'q' ){
	if( is_same_set( a, b ) )
	  ++ success;
	else
	  ++ unsuccess;
      }
    }
    printf("%d,%d\n", success, unsuccess);
    if( tc ) printf("\n");
  }
  return 0;
}
