#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int MAXN = 550;
int p[11] {};
int buckets[10][2] {};
vector<string> vals( MAXN );

inline ll msd( ll n ){
  ll k{n};
  while( k > 10 ) k /= 10;
  return k;
}

inline ll msd( string s ){
  return s[0] - '0';
}

string score( ll n ){
  string ans {};
  ll k{n}, sm{10}, la{-1};
  while( k > 0 ){
    ll tmp {k % 10};
    if( tmp > la ) la = tmp;
    if( tmp < sm ) sm = tmp;
    k /= 10;
  }
  ll sc = la * 11LL + sm * 7LL;
  ans = to_string( sc );
  if( ans.length() > 2U ) ans = ans.substr( 1, 2 );
  return ans;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, tmp {};
  cin >> n;
  // compute scores
  for( int i = 0; i < n; ++ i ){
    cin >> tmp;
    vals[i] = score( tmp );
  }
  for( int i = 0; i < n; ++ i )
    buckets[msd(vals[i])][(i + 1) % 2] ++;

  int total {};
  for( int i = 0; i < 10; ++ i ){
    if( buckets[i][0] >= 3 or buckets[i][1] >= 3 ) total += 2;
    else total += (buckets[i][0] == 2) + (buckets[i][1] == 2);
  }
  cout << total << endl;
  return 0;
}
