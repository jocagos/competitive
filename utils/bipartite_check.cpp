#include <bits/stdc++.h>

using namespace std;

bool is_bip(){
  queue<int> q;
  q.push( source ); // source
  vi color( MAXN, INF );
  color[source] = 0;
  bool is = true;
  while( not q.empty() and is ){
    int u = q.front();
    q.pop();
    for( auto v : g[u] ){
      if( color[v] == INF ){
	color[v] = 1 - color[u];
	q.push( v );
      }
      else if( color[v] == color[u] ){
	is = false;
	break;
      }
    }
  }
  return is;
}
