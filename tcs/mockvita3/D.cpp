#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t {}, n {};
  cin >> n >> t;
  vector<vector<int>> times( n, vector<int>( t ) );
  vector<int> steps( n );
  for( int i = 0; i < n; ++ i )
    for( int j = 0; j <= t; ++ j ){
      if( j < t )
	cin >> times[i][j];
      else
	cin >> steps[i];
    }
  for( int i = 0; i < n; ++ i ){
    for( int j = 1; j < t; ++ j ){
      times[i][j] += times[i][j - 1];
    }
  }
  for( int i = 0; i < n; ++ i ){
    for( int j = 0; j < t; ++ j ){
      times[i][j] *= steps[i];
    }
  }
  vector<int> buckets( n, 0 );
  for( int idx = 1; idx < t; idx += 2 ){
    int ma {-1};
    for( int i = 0; i < n; ++ i )
      if( times[i][idx] > ma )
	ma = times[i][idx];
    pair<int, int> pos { -1, -1 };
    for( int i = 0; i < n and (pos.first == -1 or pos.second == -1); ++ i )
      if( times[i][idx] == ma ){
	if( pos.first == -1 )
	  pos.first = i;
	else if( pos.second == -1 )
	  pos.second = i;
      }
    buckets[pos.first] ++;
    if( pos.second != -1 )
      buckets[pos.second] ++;
  }
  int mx {0};
  for( int i = 1; i < n; ++ i )
    if( buckets[i] > buckets[mx] )
      mx = i;
  cout << mx + 1 << endl;
  return 0;
}
