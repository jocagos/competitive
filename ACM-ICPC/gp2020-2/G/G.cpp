#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 110;
vector<int> kadane( MAXN, 0 );

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int C {};
  cin >> C;
  for( int i = 1; i <= C; ++ i )
    cin >> kadane[i];
  kadane[0] = 100;
  int M = kadane[0];
  for( int i = 1; i <= C; ++ i ){
    kadane[i] += kadane[i - 1];
    if( kadane[i] > M )
      M = kadane[i];
  }
  cout << M << '\n';
  return 0;
}
