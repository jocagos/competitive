#include <bits/stdc++.h>

using namespace std;
int tc {}, n {}, h {};
bool used[1 << 18] {};
set<int> vals {};

void solve( int bitmask = 0 ){
  if( used[bitmask] ) return;
  if( bitmask >= (1 << n) ) return;
  if( __builtin_popcount( bitmask ) == h ) vals.emplace( bitmask ), used[bitmask] = true;
  else{
    for( int i = 0; i < n; ++ i ){
      solve( bitmask | (1 << i) );
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> tc;
  while( tc -- ){
    cin >> n >> h;
    // V1.0 - Iterate through all valid possibilities
    // for( int i = 1; i < (1<<n); ++ i )
    //   if( __builtin_popcount( i ) == h ){
    // 	for( int bit = n-1; bit >= 0; -- bit )
    // 	  cout << ((i & (1 << bit)) ? 1 : 0);
    // 	cout << '\n';
    //   }
    // V2.0 - next_permutation
    string s( n, '0' );
    for( int i = n - 1; i >= (n-h); -- i ) s[i] = '1';
    do{
      cout << s << '\n';
    } while( next_permutation( s.begin(), s.end() ) );
    if( tc ) cout << '\n';
  }
  return 0;
}
