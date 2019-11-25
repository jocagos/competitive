#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 200200;
constexpr long long MAXBIN = 2e9;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<long long> v( MAXN );
  set<long long> s;
  for( int i = 0; i < n; ++ i ){
    cin >> v[i];
    s.emplace( v[i] );
  }
  for( int i = 0; i < n; ++ i ){
    for( long long j = 1LL; j <= MAXBIN; j <<= 1 ){
      if( s.count( v[i] + j ) and s.count( v[i] + 2 * j ) ){
	cout << 3 << '\n' << v[i] << " " << v[i] + j << " " << v[i] + 2 * j << '\n';
	return 0;
      }
    }
  }
  for( int i = 0; i < n; ++ i ){
    for( long long j = 1LL; j <= MAXBIN; j <<= 1 ){
      if( s.count( v[i] + j ) ){
	cout << 2 << '\n' << v[i] << " " << v[i] + j << '\n';
	return 0;
      }
    }
  }
  cout << 1 << '\n' << v[0] << '\n';
  return 0;
}
