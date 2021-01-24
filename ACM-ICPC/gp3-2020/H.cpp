#include <iostream>
#include <vector>
#include <tuple>
#include <set>
#include <cmath>
#include <algorithm>
#include <utility>
#include <bitset>

using namespace std;
// using __builtin_popcount = __builtin_popcount;

int threshold {}, total {};
int n {}, g {};
set<int> sols;
vector<int> arr;

int count_bits( long long n ){
  int c {};
  for( int i = 0; i < (int)sizeof( long long ) * 8; ++ i ){
    if( n & (1 << i) ) ++ c;
  }
  return c;
}

int get_score( int bitmask ){
  int total {};
  for( int i = 0; i < n; ++ i ){
    if( bitmask & (1 << i) )
      total += arr[i];
  }
  return total;
}

void solve( int bitmask, int score ){
  if( score >= threshold ){
    sols.emplace( bitmask );
    cerr << "Tried to emplace (" << bitmask << ", " << score << ")\n";
    return;
  }
  else{
    for( int i = 0; i < n; ++ i ){
      if( bitmask & (1 << i) ){
	continue;
      }
      else{
	solve( bitmask | (1 << i), score + arr[i] );
	if( sols.find( bitmask ) == sols.end() )
	  solve( bitmask, score );
      }
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
    int min_probs = __builtin_popcount(*sols.begin());
    auto _last = sols.begin();
    while( _last != sols.end() ){
      if( __builtin_popcount(*_last) > min_probs )
	break;
      ++ _last;
    }
    auto it = sols.begin();
    cout << min_probs << std::distance( it, _last ) << '\n';
    while( it != _last ){
      cout << (get_score( *it ) * 100.0 / total);
      int bitmask = *it;
      for( int i = 0; i < n; ++ i )
	if( bitmask & (1 << i) ) cout << " " << (i + 1);
      cout << '\n';
    }
  }
  return 0;
}
