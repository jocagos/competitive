#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <functional>
#include <cstring>
#include <tuple>

using namespace std;
constexpr int MAXK = 755, INF = 999999999;
int tmp[MAXK] {};
bool used[MAXK][MAXK] {};
vector<vector<int>> lines( MAXK, vector<int>( MAXK, INF ) );

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int k {};
  while( cin >> k ){
    for( int i = 0; i < k; ++ i ){
      for( int j = 0; j < k; ++ j )
	cin >> lines[i][j];
      lines[i][k] = INF;
      sort( lines[i].begin(), lines[i].begin() + k );
      if( i > 0 ){
	memset( used, 0, sizeof used );
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	used[0][0] = true;
	pq.emplace( lines[i - 1][0] + lines[i][0], 0, 0 );
	for( int j = 0; j < k; ++ j ){
	  auto t = pq.top();
	  pq.pop();
	  int val, a, b;
	  tie( val, a, b ) = t;
	  if( not used[a + 1][b] ){
	    pq.emplace( lines[i - 1][a + 1] + lines[i][b], a + 1, b );
	    used[a + 1][b] = true;
	  }
	  if( not used[a][b + 1] ){
	    pq.emplace( lines[i - 1][a] + lines[i][b + 1], a, b + 1 );
	    used[a][b + 1] = true;
	  }
	  tmp[j] = val;
	}
	for( int j = 0; j < k; ++ j )
	  lines[i][j] = tmp[j];
      }
    }
    for( int i = 0; i < k; ++ i )
      cout << lines[k - 1][i] << (i + 1 == k ? "\n" : " ");
  }
  return 0;
}
