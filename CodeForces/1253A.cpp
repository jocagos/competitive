#include <bits/stdc++.h>
#define dbg(x) cerr << #x << ": " << (x) << endl;

using namespace std;

constexpr int MAXN = 100100;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  vector<int> a( MAXN ), b( MAXN ), diff( MAXN );
  while( tc -- ){
    int n {};
    int tmp_diff {-999999};
    cin >> n;
    for( int i = 0; i < n; ++ i )
      cin >> a[i];
    for( int i = 0; i < n; ++ i ){
      cin >> b[i];
      diff[i] = b[i] - a[i];
    }
    auto it = find_if_not( diff.begin(), diff.begin() + n, []( int n ){ return n == 0; } );
    tmp_diff = ( it == diff.begin() + n ? 0 : *it );
    long int idx_begin {it - diff.begin()}, idx_end {};
    idx_end = idx_begin + 1;
    while( idx_end < n and diff[idx_end] == tmp_diff ) idx_end ++;
    auto it2 = find_if_not( diff.begin() + idx_end, diff.begin() + n, []( int n ){ return n == 0; } );
    if( it2 != diff.begin() + n or tmp_diff < 0 ) cout << "NO\n";
    else cout << "YES\n";
  }
  return 0;
}
