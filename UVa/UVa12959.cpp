#include <cstdio>
#include <cstring>

using namespace std;

constexpr int MAXN = 505;
int points[MAXN] {};
int r {}, p {}, tmp {};

int main(){
  int tint = sizeof(int);
  while( scanf("%d %d\n", &p, &r) != EOF ){
    memset( points, 0, tint * p );
    for( int i = 0; i < r; ++ i ){
      for( int j = 0; j < p; ++ j ){
	scanf("%d", &tmp);
	points[j] += tmp;
      }
    }
    int max = points[p - 1];
    int idx = p - 1;
    for( int i = p - 2; i >= 0; -- i ){
      if( points[i] > max ){
	max = points[i];
	idx = i;
      }
    }
    printf("%d\n", idx + 1);
  }
  return 0;
}
