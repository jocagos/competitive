#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

ii kadane2d( vector<vector<int>>& arr ){
  vector<vector<int>> kad( begin( arr ), end( arr ) );
  for( unsigned i = 1; i < kad.size(); ++ i ){
    for( unsigned j = 0; j < kad[i].size(); ++ j ){
      kad[i][j] += kad[i-1][j];
    }
  }
  int ans = 0;
  for( unsigned top = 1; top < kad.size(); ++ top ){
    for( unsigned bot = top; bot < kad[top].size(); ++ bot ){
      vector<int> sums;
      for( unsigned i = 0; i < kad[top].size(); ++ i )
	sums[i] = kad[bot][i] - kad[top - 1][i];
      ans = max( ans, kadane1d( sums ) );
    }
  }
  return ans;
  /*
   * if we need the range we just need to save the position of the max and iterate backwards looking for the previous zero.
   */
}
