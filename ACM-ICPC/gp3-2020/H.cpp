#include <iostream>
#include <vector>
#include <tuple>
#include <set>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;

int threshold {}, total {};
int n {}, g {};
set<tuple<int, int>> sols;
vector<int> arr;

int count_bits( long long n ){
  int c {};
  for( int i = 0; i < (int)sizeof( long long ) * 8; ++ i ){
    if( n & (1 << i) ) ++ c;
  }
  return c;
}

void solve( int bitmask, int score ){
  if( score >= threshold ){
    sols.emplace( bitmask, score );
    return;
  }
  for( int i = 0; i < n; ++ i ){
    if( bitmask & (1 << i) ){
      continue;
    }
    else{
      solve( bitmask | (1 << i), score + arr[i] );
      solve( bitmask, score );
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> g;
  arr.assign(n, 0);
  for( int i = 0; i < n; ++ i ){
    cin >> arr[i];
    threshold += arr[i];
    total += arr[i];
  }
  // set up the min value of points needed
  threshold = ceil(threshold * (g / 100.0));
  solve( 0, 0 );
  if( sols.size() ){
    auto f = *sols.begin();
    int min_probs = get<0>( f );
    auto _last = sols.begin();
    while( _last != sols.end() ){
      if( get<0>(*_last) > min_probs )
	break;
      ++ _last;
    }
    auto it = sols.begin();
    cout << min_probs << std::distance( it, _last ) << '\n';
    while( it != _last ){
      cout << int(get<1>( *it ) * 100.0 / total);
      int bitmask = get<0>(*it);
      for( int i = 0; i < n; ++ i )
	if( bitmask & (1 << i) ) cout << " " << (i + 1);
      cout << '\n';
    }
  }
  return 0;
}
