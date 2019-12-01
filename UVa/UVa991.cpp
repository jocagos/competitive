#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 12;
unsigned long long f[MAXN * 2] {};

void init(){
  f[0] = f[1] = 1;
  for( int i = 2; i < MAXN * 2; ++ i)
    f[i] = f[i - 1] * i;
}

inline unsigned long long cat( int n ){
  return f[2*n] / f[n] / f[n] / (n + 1);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, tc {-1};
  init();
  while( cin >> n ){
    if( ++ tc ) cout << '\n';
    cout << cat( n ) << '\n';
  }
  return 0;
}
