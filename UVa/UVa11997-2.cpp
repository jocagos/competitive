#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <functional>
#include <cstring>

using namespace std;

constexpr int MAXK = 755, INF = 99999999;
bool used[MAXK][MAXK] {}; // 755 * 755 ~= 600k
vector<int> lhs( MAXK, INF ), rhs( MAXK, INF );

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int k {};
  vector<int> vals( MAXK, INF );
  while( cin >> k ){
    for( int i = 0; i < k; ++ i )
      cin >> lhs[i];
    sort( lhs.begin(), lhs.begin() + k );
    for( int t = 1; t < k; ++ t ){
      memset( used, false, sizeof used );
      for( int i = 0; i < k; ++ i )
	cin >> rhs[i];
      sort( rhs.begin(), rhs.begin() + k );
      priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq {};
      used[0][0] = true;
      pq.emplace( lhs[0] + rhs[0], 0, 0 );
      for( int i = 0; i < k; ++ i ){
	int val, x, y;
	tie( val, x, y ) = pq.top();
	pq.pop();
	vals[i] = val;
	if( not used[x + 1][y] ){
	  used[x + 1][y] = true;
	  pq.emplace( lhs[x + 1] + rhs[y], x + 1, y );
	}
	if( not used[x][y + 1] ){
	  used[x][y + 1] = true;
	  pq.emplace( lhs[x] + rhs[y + 1], x, y + 1 );
	}
      } // for it algo
      for( int i = 0; i < k; ++ i )
	lhs[i] = vals[i];
    } // k-1 iters
    for( int i = 0; i < k; ++ i )
      cout << vals[i] << (i + 1 == k ? '\n' : ' ');
  }
  return 0;
}
