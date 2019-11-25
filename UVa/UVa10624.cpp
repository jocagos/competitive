#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

i64 N, M;

bool able( i64 n, int m ){
  bool ans = true;
  for( int i = 1; i <= m; ++ i ){
    
  }
  return ans;
}

i64 backtrack( i64 n, int m ){
  if( m == M ) return n;
  n *= 10;
  i64 t = n;
  while( n % m ){
    
  }
  return backtrack( n, m + 1 );
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  for( int CASE = 1; CASE <= tc; ++ CASE ){
    cin >> N >> M;
    auto ans = backtrack( 1, 1 );
    cout << "Case " << CASE << ": " << ans << endl;
  }
  return 0;
}
