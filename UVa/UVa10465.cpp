#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
constexpr int MAX = 22222;
int n, m;
int memo[MAX];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t {};
  while( cin >> n >> m >> t ){
    memset( memo, -1, sizeof( memo ) );
    memo[0] = 0;
    for( int i = 1; i <= t; ++ i ){
      int a = (i - m >= 0 ? memo[i - m] : -1);
      if( a >= 0 ) ++ a;
      int b = (i - n >= 0 ? memo[i - n] : -1);
      if( b >= 0 ) ++ b;
      memo[i] = max( a, b );
    }
    if( memo[t] != -1 ) 
      cout << memo[t] << '\n';
    else{
      int i = t;
      while( memo[i] == -1 ) -- i;
      cout << memo[i] << " " << (t - i) << '\n';
    }
  }
  return 0;
}
