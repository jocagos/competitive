#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cstdlib>
#include <cstring>

using namespace std;
constexpr int MAXN {505}, MAXM {10010}, INF = 1e9;

vector<vector<pair<int, int>>> g( MAXN );
vector<int> path( MAXN );
bool prep {};
bool invalid[MAXN][MAXN] {};

int dijkstra( int source, int destination ){
  using ii = pair<int, int>;
  if( prep ){
    int it = destination;
    while( it != source and it != -1 ){
      int f = path[it];
      invalid[f][it] = true;
      it = f;
    }
    prep = false;
  }
  else return INF;
  vector<int> dist( MAXN, INF );
  path.assign( MAXN, -1 );
  dist[source] = 0;
  priority_queue<ii, vector<ii>, greater<ii> > pq {};
  pq.emplace( 0, source );
  while( not pq.empty() ){
    int curr_dist = pq.top().first, curr_ver = pq.top().second;
    if( curr_dist > dist[curr_ver] ) continue;
    for( int i = 0; i < (int)g[curr_ver].size(); ++ i ){
      int new_dist = g[curr_ver][i].first, new_ver = g[curr_ver][i].second;
      if( not invalid[curr_ver][new_ver] and new_dist + dist[curr_ver] < dist[new_ver] ){
	dist[new_ver] = dist[curr_ver] + new_dist;
	path[new_ver] = curr_ver;
	pq.emplace( dist[new_ver], new_ver );
      }
    }
  }
  int it = destination;
  while( it != source and it != -1 ){
    it = path[it];
  }
  if( it == source ) prep = true;
  return dist[destination];
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, m {}, s {}, d {};  
  while( cin >> n >> m, n | m ){
    // prep mem
    for( int i = 0; i < n; ++ i )
      g[i].clear();
    memset( invalid, 0, sizeof invalid );
    // get start and end
    cin >> s >> d;
    // get edges
    for( int i = 0; i < m; ++ i ){
      int _from {}, _to {}, _w {};
      cin >> _from >> _to >> _w;
      g[_from].emplace_back( _w, _to );
    }
    // dijkstra - modified
    int min_dist = dijkstra( s, d );
    int new_dist {INF};
    do{
      new_dist = dijkstra( s, d );
    } while( new_dist == min_dist and prep );
    if( new_dist == INF ) cout << "-1\n";
    else cout << new_dist << '\n';
  }
  return 0;
}
