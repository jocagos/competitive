#include <bits/stdc++.h>

using namespace std;
using ii = pair<long, long>;
constexpr int MAXN = 10000000;
constexpr int MAXM = ceil((-1 + sqrt(1 + 8 * MAXN))/2) + 20;
long memo[MAXM] {};

void init(){
  memo[0] = 0;
  for( int i = 1; i < MAXM; ++ i ) memo[i] = i + memo[i - 1];
}

inline ii s( long n ){
  if( n < 0 ) return ii(-1, -1);
  auto it = lower_bound( memo, memo + MAXM, n );
  return ii((it - memo) - 1, it - memo);
}

ii f( long n ){
  ii rang = s( n );
  // cerr << "n = " << n << " yields { " << rang.first << ", " << rang.second << " }" << endl;
  long k{rang.first * (rang.first + 1) / 2 + 1};
  long steps{n - k};
  // cerr << "k is " << k << endl;
  // cerr << "r is " << r << endl;
  
  long num{1 + steps}, den{rang.second - steps};
  if( rang.second & 1 )
    swap(num, den);
  return ii(num, den);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  init();
  long n;
  while( cin >> n ){
    auto ans = f( n );
    cout << "TERM " << n << " IS " << ans.first << "/" << ans.second << '\n';
  }
  return 0;
}
