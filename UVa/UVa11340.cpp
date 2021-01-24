#include <iostream>
#include <cstring>
using namespace std;
constexpr int MAXN = 10010;
// This solution takes about 0.010s/1.000s, it can still be improved by reading characters one at a time
int main(){
  int t;
  int vals[260];
  char line[MAXN] {};
  scanf("%d\n", &t);
  while(t--){
    memset(vals, 0, sizeof vals);
    int k, v, sum = 0;
    int c {};
    // string line, lines {};
    scanf("%d\n", &k);
    for( int i = 0; i < k; ++i ){
      scanf("%c %d\n", &c, &v);
      vals[c+128] = v;
    }
    scanf("%d\n", &k);
    
    for( int i = 0; i < k; ++i ){
      fgets( line, MAXN, stdin );
      // c = '\0';
      // while( c != '\n' and feof( stdin ) == 0 ){
	// c = getc( stdin );
	// fprintf( stderr, "c is %c and %d, and i is %d\n", (char)c, c, i );
      int j {};
      while( line[j] != '\0' )
	sum += vals[line[j ++] + 128];
      // }
    }
    printf("%d.%02d$\n", sum / 100, sum % 100);
  }
  return 0;
}
