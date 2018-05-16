#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define abs( x ) ( (x) > 0 ? (x) : (-(x)) )

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(){
  int n;
  while( scanf("%d ", &n) != EOF ){
    vii ones, threes;
    vector<int> dists, ans;
    char c;
    for( int i = 1; i <= n; ++i ){
      for( int j = 1; j <= n; ++j ){
	c = getchar();
	if( c == '1' ) ones.emplace_back(i, j);
	if( c == '3' ) threes.emplace_back(i, j);
      }
      c = getchar(); // catch the newline
      if( c == '\r' ) c = getchar();
    }
    for( auto x : ones ){
      dists.clear();
      for( auto y : threes ){
	dists.push_back( abs( x.first - y.first ) + abs( x.second - y.second ) );
      }
      sort(dists.begin(), dists.end());
      ans.push_back(dists[0]);
    }
    sort(ans.begin(), ans.end());
    cout << ans[ans.size()-1] << endl;
  }
  return 0;
}
