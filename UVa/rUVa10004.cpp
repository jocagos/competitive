constexpr int MAXN = 210;
constexpr int BLACK = 1, WHITE = 0, NC = -1;
int n, m;
vi color( MAXN, NC );
bool ans = true, v[MAXN];
vector<vi> g;

bool dfs( int u = 0 ){
  for( auto p : g[u] ){
    if( not v[p] ){
      v[p] = V;
      color[p] = (1 ^ color[u]);
      if( not dfs( p ) ) return false;
    }
    else if( color[u] == color[p] ) return false;
  }
  return true;
}

int main(void){
  fastio;
  while( cin >> n, n ){
    memset( v, false, sizeof v );
    ans = true;
    fill( all( color ), NC );
    prepare( g, n );
    cin >> m;
    REP( i, m ){
      int x, y;
      cin >> x >> y;
      g[x].EB( y );
      g[y].EB( x );
    }
    color[0] = BLACK;
    if( ans ) cout << "BICOLORABLE.\n";
    else cout << "NOT BICOLORABLE.\n";
    REP( i, n ){
      cout << "Node (" << i << ", " << (color[i] ? "B" : "W") << "): {";
      REP( j, (int)g[i].size() ) cout << " (" << g[i][j] << ", " << (color[g[i][j]] ? "B" : "W") << ")";
      cout << "}\n";
    }
  }
  return 0;
}
