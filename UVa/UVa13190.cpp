#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
#include <functional>

using namespace std;
constexpr int MAXN = 1e4;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> periods( MAXN );
  vector<string> vs( MAXN );
  string s {};
  int tc {}, n {}, k {}, period {}, prio;
  cin >> tc;
  while( tc -- ){
    cin >> n >> k;
    priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int>>> pq;
    for( int i = 0; i < n; ++ i ){
      cin >> s >> periods[i];
      vs[i] = s;
      pq.emplace( periods[i], i );
    }
    while( k -- ){
      auto tmp = pq.top();
      pq.pop();
      tie( period, prio ) = tmp;
      cout << period << " " << vs[prio] << '\n';
      pq.emplace( period + periods[prio], prio );
    }
  }
  return 0;
}
