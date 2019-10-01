#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

ii kadane( vector<int>& arr ){
  vector<int> kad( begin( arr ), end( arr ) );
  for( unsigned i = 1; i < kad.size(); ++ i ){
    kad[i] += kad[i - 1];
    if( kad[i] < 0 ) kad[i] = 0;
  }
  // if we need the actual range
  /*
  int mx_idx = max_element( begin( kad ), end( kad ) ) - begin( kad );
  int mx_begin = mx_idx;
  while( mx_begin >= 0 ){
    if( kad[mx_begin] == 0 ) break;
    mx_begin --;
  }
  
  return { mx_begin, mx_idx };
  */
  // otherwise we jsut return max element
  return *max_element( begin( kad ), end( kad ) );
}
