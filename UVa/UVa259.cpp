#include <bits/stdc++.h>

using namespace std;
constexpr int INF = 1e18, MAXV = 40, SOURCE = 0, SINK = 38;
int res[MAXV][MAXV] {}, mf {}, f {}, s {}, t {};
int g[MAXV][MAXV] {};
vector<int> p {};

class MaxFlow {
private:
  using ll = long long;
  using edge = tuple<int, int, ll, ll>;
  using vi = vector<int>;
  using ii = pair<int, int>;
  int V;
  vector<edge> EL;
  vector<vi> AL;
  vi d, last;
  vector<ii> p;

  bool BFS( int s, int t ){
    d.assign( V, -1 );
    d[s] = 0;
    queue<int> q( {s} );
    p.assign( V, {-1, -1} );
    while( not q.empty() ){
      int u = q.front();
      q.pop();
      if( u == t ) break;
      for( auto& idx : AL[u] ){
	int a {}, b {};
	ll c {}, d {};
	tie( a, b, c, d ) = EL[idx];
	if( (cap
      }
    }
  }
};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string line {};
  int V {}, k {}, vertex {}, weight {};
  while( getline( cin, line ) ){
    memset( g, 0, sizeof 0 );
    for( int i = 27; i <= 37; ++ i ) g[i][SINK] = 1;
    if( line != "" ){
      int machine = line[0] - 'A' + 1;
      int qty = line[1] - '0';
      g[SOURCE][machine] = qty;
      for( int i = 3; i < line.length() - 1; ++ i ){
	int tmp = line[i] - '0';
	g[machine][tmp + 27] = INF;
      }
    }
    else{
      // do max flow
      // stop cycle
      // show answers
    }
  }
  cin >> V >> s >> t;
  memset( res, 0, sizeof res );
  for( int i = 0; i < V; ++ i ){
    cin >> k;
    for( int j = 0; j < k; ++ j ){
      cin >> vertex >> weight;
      res[i][vertex] = weight;
    }
  }

  mf = 0;
  while( true ){
    f = 0;
    vector<int> dist( MAXV, INF );
    dist[s] = 0;
    queue<int> q;
    q.push( s );
    p.assign( MAXV, -1 );
    while( not q.empty() ){
      int u = q.front();
      q.pop();
      if( u == t ) break;
      for( int v = 0; v < MAXV; ++ v ){
	if( res[u][v] > 0 and dist[v] == INF )
	  dist[v] = dist[u] + 1, q.push( v ), p[v] = u;
      }
    }
    augment( t, INF );
    if( f == 0 ) break;
    mf += f;
  }
  cout << mf << '\n';
  return 0;
}
