#include <cstdio>
#include <cstring>

using namespace std;
constexpr int MAXT = 100010;
// Using bitmasks:
// * 4 = 100 = L
// * 2 = 010 = R
// * 1 = 001 = S
// IF someone has a unique chocolate, it's either L, R, or S
// on the other hand, if someone does not have a chocolate
// then it is 7 - L/R/S

int main(){
  int tc {};
  scanf("%d", &tc);
  for( int CASE = 1; CASE <= tc; ++ CASE ){
    int L {}, R {}, S {}, tmp {};
    int chocolates[MAXT] {};
    int unique[3] {}, others[3] {};
    scanf("%d %d %d", &L, &R, &S);
    for( int i = 0; i < L; ++ i ){
      scanf("%d", &tmp);
      if( not (chocolates[tmp] & 4) )
	chocolates[tmp] += 4;
    }
    for( int i = 0; i < R; ++ i ){
      scanf("%d", &tmp);
      if( not (chocolates[tmp] & 2) )
	chocolates[tmp] += 2;
    }
    for( int i = 0; i < S; ++ i ){
      scanf("%d", &tmp);
      if( not (chocolates[tmp] & 1) )
	chocolates[tmp] += 1;
    }
    for( int i = 0; i < MAXT; ++ i ){
      if( chocolates[i] == 1 )
	++ unique[2];
      else if( chocolates[i] == 2 )
	++ unique[1];
      else if( chocolates[i] == 3 )
	++ others[0];
      else if( chocolates[i] == 4 )
	++ unique[0];
      else if( chocolates[i] == 5 )
	++ others[1];
      else if( chocolates[i] == 6 )
	++ others[2];
    }
    printf("Case #%d:\n", CASE);
    for( int i = 0; i < 3; ++ i )
      printf("%d %d\n", unique[i], others[i]);
  }
  return 0;
}
