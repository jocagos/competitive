#include <bits/stdc++.h>

using namespace std;
using pqii = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >;

constexpr int MAXN = 10100, MAXM = 100100;
constexpr int INF = 1e9;
vector<vector<pair<int, int>>> al( MAXN );
vector<vector<pair<int, int>>> ral( MAXN );
vector<tuple<int, int, int>> el( MAXM );

int tc, n, m, s, t, p;
unsigned int elidx;

void dijkstra( int source, int target, vector<vector<pair<int, int>>>& adl, long long * dist ){
  for( int i = 0; i < MAXN; ++ i ) dist[i] = INF;
  dist[source] = 0;
  pqii pq;
  pq.emplace( 0, source );
  while( not pq.empty() ){
    auto t = pq.top();
    pq.pop();
    int c = t.first, u = t.second;
    if( c > dist[u] ) continue;
    for( auto tmp : adl[u] ){
      int v = tmp.first, d = tmp.second;
      if( dist[u] + d < dist[v] ){
	dist[v] = dist[u] + d;
	pq.emplace( dist[v], v );
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> tc;
  while( tc -- ){
    cin >> n >> m >> s >> t >> p;
    elidx = 0;
    for( int i = 0; i < m; ++ i ){
      int u, v, c;
 cin >> u >> v >> c;
      al[u].emplace_back( v, c );
      ral[v].emplace_back( u, c );
      el[elidx] = { u, v, c };
      elidx ++;
    }
    long long dist[MAXN], dist2[MAXN];
    dijkstra( s, t, al, dist );
    dijkstra( t, s, ral, dist2 );
    int m = -1;
    for( int i = 0; i < (int)elidx; ++ i ){
      int u, v, c;
      tie( u, v, c ) = el[i];
      if( dist2[v] + c + dist[u] <= p ) m = max( c, m );
    }
    int ans = m;
    cout << ans << endl;
    // clear memory
    for( int i = 0; i < n; ++ i ){
      al[i].clear();
      ral[i].clear();
    }
  }
  return 0;
}
