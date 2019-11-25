#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 10010, DIG = 10;
bool done[MAXN] {};
int memo[MAXN][DIG] {};

void dp( ){
  for( int i = 1; i < MAXN; ++ i ){
    for( int d = 0; d < DIG; ++ d ) memo[i][d] += memo[i - 1][d];
    int ii = i;
    while( ii ){
      int d = ii % 10;
      memo[i][d] ++;
      ii /= 10;
      // cerr << "ii is now " << ii << endl;
    }
    done[i] = true;
    // cerr << i << " is done" << endl;
  }
  // cerr << "my job here is done!" << endl;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  dp();
  int n {};
  cin >> n;
  while( n -- ){
    int k;
    cin >> k;
    for( int i = 0; i < DIG; ++ i )
      cout << memo[k][i] << ( i + 1 == DIG ? "\n" : " " );
  }
  return 0;
}
