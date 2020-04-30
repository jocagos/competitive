#include <iostream>

using namespace std;

constexpr int MAXN {65};
unsigned long long memo[MAXN][MAXN] {};

unsigned long long dp( int n, int b ){
  if( n <= 1 or b <= 0 ) return 1ULL;
  if( memo[n][b] != -1 ) return memo[n][b];
  else{
    memo[n][b] = 1;
    for( int i = 1; i <= b; ++ i )
      memo[n][b] += dp( n - i, b );
  }
  return memo[n][b];
}

void init(){
  for( int i = 0; i < MAXN; ++ i )
    for( int j = 0; j < MAXN; ++ j )
      memo[i][j] = -1;
  // base cases
  for( int i = 0; i < MAXN; ++ i ){
    memo[i][0] = memo[0][i] = memo[1][i] = 1;
  }
  for( int i = 1; i < MAXN; ++ i )
    for( int j = 1; j < MAXN; ++ j )
      dp( i, j );
}

int main(){
  int TC {};
  int n {}, b {};
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  init();
  // for( int i = 0; i < MAXN; ++ i )
  //   for( int j = 0; j < MAXN; ++ j )
  //     cerr << memo[i][j] << (j + 1 == MAXN ? "\n" : " ");
  while( cin >> n >> b ){
    if( n > 60 or b > 60 )
      exit(0);
    cout << "Case " << ++ TC << ": " << dp( n, b ) << '\n';
  }
  return 0;
}
