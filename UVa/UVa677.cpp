#include <bits/stdc++.h>

using namespace std;
constexpr int MAXV = 10;
int V {}, n {};
bitset<MAXV> vis {};
int mat[MAXV][MAXV] {};
vector<vector<int>> al {};

struct Cmp {
  bool operator() ( const string& lhs, const string& rhs ) const
  {
    return lexicographical_compare( begin( lhs ), end( lhs ), begin( rhs ), end( rhs ) );
  }
};

set<string, Cmp> paths;
// don't repeat nodes!
void dfs( int u, string path, int rem = n ){
  vis[u] = true;
  if( rem == 0 )
    paths.emplace( path + to_string( u + 1 ) + ")\n" ); 
  else{
    for( auto neighbour : al[u] )
      if( not vis[neighbour] )
	dfs( neighbour, (path + to_string(u + 1)) + ",", rem - 1 );
  }
  vis[u] = false;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tmp {-9999};
  do{
    cin >> V >> n;
    al.assign( V, vector<int>() );
    paths.clear();
    vis.reset();
    for( int i = 0; i < V; ++ i ){
      for( int j = 0; j < V; ++ j ){
	cin >> mat[i][j];
	if( mat[i][j] ) al[i].emplace_back( j ), al[j].emplace_back( i );
      }
    }
    dfs( 0, "(" );
    if( paths.size() )
      for( auto& path : paths ) cout << path;
    else cout << "no walk of length " << n << endl;
    if( cin >> tmp ){
      ;
    }
    else tmp = 0;
    if( tmp ) cout << "\n";
  } while( tmp == -9999 );
  return 0;
}
