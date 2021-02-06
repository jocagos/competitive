#include <cstdio>
#include <iostream>
#include <iomanip>

using namespace std;
constexpr int MAXN = 20020;
int n {};
int pa[MAXN] {}, ra[MAXN] {};

inline void init( int n = MAXN ){
  for( int i = 0; i < n; ++ i ){
    pa[i] = i;
    ra[i] = 1;
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
    int x = find_set( i ), y = find_set( j );
    if( ra[x] < ra[y] ){
      pa[x] = y;
      ra[y] += ra[x];
    }
    else{
      pa[y] = x;
      ra[x] += ra[y];
    }
    return true;
  }
  return false;
}

inline int en( int i ){
  return i + n;
}

int main(){
  int q {}, a {}, b {};
  while( scanf("%d", &n) == 1 ){
    init();
    while( scanf("%d %d %d", &q, &a, &b) == 3 ){
      int x = find_set( a ), y = find_set( b );
      int ex = find_set( en( a ) ), ey = find_set( en( b ) );
      if( q == 1 ){ // set_friends
	if( x == ey or ex == y )
	  printf("-1\n");
	else{
	  union_set( a, b );
	  union_set( en( a ), en( b ) );
	}
      }
      else if( q == 2 ){ // set_enemies
	if( x == y or ex == ey )
	  printf("-1\n");
	else{
	  union_set( a, en( b ) );
	  union_set( en( a ), b );
	}
      }
      else if( q == 3 ){ // are_friends
	if( x == y or ex == ey )
	  printf("1\n");
	else
	  printf("0\n");
      }
      else if( q == 4 ){ // are_enemies
	if( x == ey or y == ex )
	  printf("1\n");
	else
	  printf("0\n");
      }
    }
  }
  return 0;
}
