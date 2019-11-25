#include <bits/stdc++.h>

using namespace std;
using ii = tuple<int, int>;
constexpr INF = 1e9 + 7, MATSIZE = 5;

int n {}, best_mask {-1}, best_sum {INF};
int used[MATSIZE * MATSIZE] {};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  while( tc -- ){
    cin >> n;
    for( int i = 0; i < n; ++ i ){
      int x {}, y {}, val {};
      cin >> x >> y >> val;
      used[MATSIZE * x + y] = val;
    }
    int mask {}, s {}, bits_seen {};
    for( int A = 0; A < MATSIZE * MATSIZE; ++ A ){
      for( int B = A + 1; B < MATSIZE * MATSIZE; ++ B ){
	for( int C = B + 1; C < MATSIZE * MATSIZE; ++ C ){
	  for( int D = C + 1; D < MATSIZE * MATSIZE; ++ D ){
	    for( int E = D + 1; E < MATSIZE * MATSIZE; ++ E ){
	      
	    }
	  }
	}
      }
    }
    do{
      
    } while( next_permutation( mask, mask + MATSIZE * MATSIZE ) );
  }
  return 0;
}
