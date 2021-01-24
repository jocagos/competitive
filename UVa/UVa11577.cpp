#include <cstdio>
#include <cstring>

using namespace std;
constexpr int MAXC = 260;
char line[MAXC] {};
int counts[MAXC] {};

int main(){
  int tc {}, idx {};
  scanf("%d\n", &tc);
  while( tc -- ){
    memset( counts, 0, sizeof counts );
    fgets( line, MAXC, stdin );
    idx = 0;
    while( line[idx] != '\0' ){
      if( ('a' <= line[idx] and line[idx] <= 'z') )
	++ counts[line[idx] - 'a'];
      else if( ('A' <= line[idx] and line[idx] <= 'Z') )
	++ counts[line[idx] - 'A'];
      ++ idx;
    }
    int mx = counts[0];
    for( int i = 0; i < MAXC; ++ i )
      if( counts[i] > mx )
	mx = counts[i];
    for( int i = 0; i < MAXC; ++ i )
      if( counts[i] == mx )
	printf("%c", (char)(i + 'a'));
    printf("\n");
  }
  return 0;
}
