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
  double disc = sqrt(1 + 8 * n);
  return ii((-1 + disc)/2, (1 + disc)/2);
}

ii f( long n ){
  ii rang = s( n );
  cerr << "n = " << n << " yields { " << rang.first << ", " << rang.second << " }" << endl;
  long k{rang.first * (rang.first + 1) / 2 + 1};
  long num{1 + n - k}, den{rang.second - k};
  if( rang.second & 1 )
    swap(num, den);
  return ii(num/gcd(num, den), den/gcd(num, den));
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
