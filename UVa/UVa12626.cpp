#include <cstdio>

using namespace std;
constexpr int MAXC = 606, MAXN = 256;
constexpr int A = 3, R = 2;

inline int min( int lhs, int rhs ){
  return (lhs < rhs ? lhs : rhs);
}

int main(){
  int tc {};
  scanf("%d\n", &tc);
  while( tc -- ){
    char line[MAXC] {};
    int counts[MAXN] {};
    fgets( line, MAXC, stdin );
    for( int i = 0; line[i] != '\0'; ++ i )
      ++ counts[line[i]];
    int ans = MAXC;
    ans = min( counts['A'] / A, ans );
    ans = min( counts['R'] / R, ans );
    ans = min( counts['M'], ans );
    ans = min( counts['I'], ans );
    ans = min( counts['G'], ans );
    ans = min( counts['T'], ans );
    printf("%d\n", ans);
  }
  return 0;
}
