#include <iostream>
using namespace std;
constexpr int MAXN = 10100;
int n, m;
int memo[MAXN];

void init(){
  for( int i = 0; i < MAXN; ++ i ) memo[i] = -1;
}

int dp( int t ){
  if( t < 0 ) return -1000000;
  if( memo[t] != -1 ) return memo[t];
  if( t == 0 ) return 0;
  return 1 + max( dp( t - m ), dp( t - n ) );
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t {};
  while( cin >> n >> m >> t ){
    init();
    int ans = dp( t );
    int _t = 0;
    for( int i = 9999; i >= 0; -- i ){
      if( memo[i] != -1 ){
	_t = 9999 - i;
	break;
      }
    }
    bool left = (_t);
    cout << ans;
    if( left ) cout << " " << _t;
    cout << '\n';
  }
  return 0;
}
