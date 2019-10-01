#include <bits/stdc++.h>
constexpr int INF = 1e9;
using namespace std;

int coins[MAXC];

int cc( int n ){
  if( n < 0 ) return INF;
  if( n == 0 ) return 0;
  int ans = INF;
  for( int i = 0; i < MAXC; ++ i )
    ans = min( ans, 1 + cc( n - coins[i] ) );
  return ans;
}
