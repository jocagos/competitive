#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6;
int cnt[MAXN + 1] {};
vector<int> ndiv( MAXN + 1, 0 ), mdiv( MAXN + 1, 0 );

void init(){
  for( int i = 1; i <= MAXN; ++ i )
    for( int j = i; j <= MAXN; j += i )
      ++ ndiv[j];
  for( int i = 1, m = 0, n = 0; i <= MAXN; ++ i ){
    if( m <= ndiv[i] ){
      m = ndiv[i];
      n = i;
    }
    mdiv[i] = n;
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  init();
  int TC {}, N {};
  cin >> TC;
  while( TC -- ){
    cin >> N;
    cout << mdiv[N] << '\n';
  }
  return 0;
}
