#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 220;
vector<int> a( MAXN ), b( MAXN );
stack<int> st;

bool vis[MAXN] {};
void dfs( int u, int cnt = 0 ){
  if( vis[u] ){
    while( not st.empty() ){
      int IDX = st.top();
      b[IDX] = cnt;
      st.pop();
    }
    return;
  }
  vis[u] = true;
  st.push( u );
  dfs( a[u], cnt + 1 );
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string line {};
  int n {};
  while( getline( cin, line ), line != "0" ){ // read until last block
    n = stoi( line );
    getline( cin, line );
    int i = 0;
    istringstream iss( line );
    while( iss >> a[i] ){
      -- a[i];
      ++ i;
    }
    memset( vis, 0, sizeof vis ); // reset every message
    for( int i = 0; i < n; ++ i )
      dfs( i );
    while( getline( cin, line ), line != "0" ){ // every block
      int ws = line.find_first_of(' ');
      int k = stoi( line.substr( 0, ws ) );
      string pre_msg = line.substr( ws + 1 );
      string msg( n, ' ' );
      for( unsigned int i = 0; i < pre_msg.length(); ++ i ) msg[i] = pre_msg[i];
      string new_msg( msg );
      for( unsigned i = 0; i < new_msg.length(); ++ i ){
        int kmod = k % b[i];
	int idx = i;
	while( kmod -- ) idx = a[idx];
	new_msg[idx] = msg[i];
      }
      cout << new_msg << '\n';
    }
    cout << '\n';
  }
  return 0;
}
