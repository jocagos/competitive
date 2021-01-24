#include <iostream>
#include <vector>

using namespace std;

constexpr int MAXN = 1010;
constexpr int UNSOLVED = -2, INF = -1;
int memo[MAXN] {};
int neighbors_x[4] = { 0, -1, 1, 0 };
int neighbors_y[4] = { -1, 0, 0, 1 };

int get_hash( string& U, string& M, string& D ){
  int H {};
  for( int i = 0; i < 3; ++ i ){
    if( U[i] == '1' )
      H += (1 << i) * 100;
    if( M[i] == '1' )
      H += (1 << i) * 10;
    if( D[i] == '1' )
      H += (1 << i);
  }
  return H;
}

int get_hash( vector<vector<int>>& g ){
  int H {};
  for( int i = 0; i < 3; ++ i ){
    if( g[0][i] )
      H += (1 << i) * 100;
    if( g[1][i] )
      H += (1 << i) * 10;
    if( g[2][i] )
      H += (1 << i);
  }
  return H;
}

bool check_grid( vector<vector<int>>& g ){
  for( int i = 0; i < 3; ++ i ){
    for( int j = 0; j < 3; ++ j ){
      if( g[i][j] ) return true;
    }
  }
  return false;
}

bool get_next( vector<vector<int>>& g ){
  vector<vector<int>> f( g.begin(), g.end() );
  for( int i = 0; i < 3; ++ i ){
    for( int j = 0; j < 3; ++ j ){
      g[i][j] = 0;
      for( int k = 0; k < 4; ++ k ){
	int Y = i + neighbors_y[k];
	int X = j + neighbors_x[k];
	if( 0 <= X and X < 3 and 0 <= Y and Y < 3 )
	  g[i][j] += f[Y][X];
      }
      g[i][j] %= 2;
    }
  }
  // now check it
  return check_grid( g );
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for( int i = 0; i < MAXN; ++ i )
    memo[i] = UNSOLVED;
  string line {};
  int tc {};
  getline( cin, line );
  tc = stoi( line );
  while( tc -- ){
    getline( cin, line ); // blank line
    string lines[3];
    getline( cin, lines[0] );
    getline( cin, lines[1] );
    getline( cin, lines[2] );
    int H = get_hash( lines[0], lines[1], lines[2] );
    if( memo[H] == UNSOLVED ){ // simulate if it hasn't been solved
      int cnt {};
      vector<vector<int>> grid(3, vector<int>(3, 0) );
      for( int i = 0; i < 3; ++ i )
	for( int j = 0; j < 3; ++ j )
	  grid[i][j] = (lines[i][j] - '0');
      if( not check_grid( grid ) )
	memo[H] = INF;
      else{
	while( true ){
	  int HH = get_hash( grid );
	  if( memo[HH] != UNSOLVED ){
	    cnt += memo[HH];
	    break;
	  }
	  if( get_next( grid ) )
	    ++ cnt;
	  else
	    break;
	} // end while
	memo[H] = cnt;
      }
      cout << memo[H] << '\n';
    } // end memo[H]
    else{
      cout << memo[H] << '\n';
    }
  }
  return 0;
}
