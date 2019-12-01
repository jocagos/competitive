#include <bits/stdc++.h>

using namespace std;
constexpr int MAXCELL = 26;
vector<vector<int>> AL( MAXCELL );
bitset<MAXCELL> awake( 0 );

int check_neighbours( int u ){
  int cnt {};
  for( auto v : AL[u] ){
    if( cnt == 3 )
      return cnt;
    if( awake[v] )
      ++ cnt;
  }
  return cnt;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string line {};
  while( getline( cin, line ) ){
    AL.assign( MAXCELL, vector<int>() );
    awake.reset();
    int n {}, m {};
    n = stoi( line );
    getline( cin, line );
    m = stoi( line );
    getline( cin, line );
    for( unsigned i {}; i < line.length(); ++ i )
      awake[line[i] - 'A'] = true;
    for( int i {}; i < m; ++ i ){
      getline( cin, line );
      AL[line[0] - 'A'].emplace_back( line[1] - 'A' );
      AL[line[1] - 'A'].emplace_back( line[0] - 'A' );
    }
    bool changed = true;
    int cnt {};
    while( changed ){
      changed = false; // to ensure it halts
      vector<int> to_awake;
      for( int i {}; i < MAXCELL; ++ i )
	if( not awake[i] )
	  if( check_neighbours( i ) == 3 )
	    to_awake.emplace_back( i );
      if( to_awake.size() )
	changed = true;
      for( auto x : to_awake )
	awake[x] = true;
      if( changed )
	++ cnt;
    }
    if( awake.count() == n )
      cout << "WAKE UP IN, " << cnt << ", YEARS\n";
    else
      cout << "THIS BRAIN NEVER WAKES UP\n";
    getline( cin, line ); // blank line
  }
  return 0;
}
