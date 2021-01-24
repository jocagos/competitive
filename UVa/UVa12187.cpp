#include <iostream>
#include <vector>

using namespace std;
constexpr int MAXN = 110;
int working_grid[MAXN][MAXN] {};
int grid[MAXN][MAXN] {};
int neighbors_x[4] = {-1, 0, 0, 1};
int neighbors_y[4] = {0, -1, 1, 0};
int n {}, r {}, c {}, k {};

void battle(){
  for( int i = 1; i <= r; ++ i )
    for( int j = 1; j <= c; ++ j ){
      int val = (grid[i][j] == n - 1 ? 0 : grid[i][j] + 1);
      for( int k = 0; k < 4; ++ k ){
	int Y = neighbors_y[k] + i;
	int X = neighbors_x[k] + j;
	
	if( grid[Y][X] == val )
	  working_grid[Y][X] = grid[i][j];
      }
    }
  for( int i = 1; i <= r; ++ i )
    for( int j = 1; j <= c; ++ j )
      grid[i][j] = working_grid[i][j];
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for( int i = 0; i < MAXN; ++ i )
    for( int j = 0; j < MAXN; ++ j )
      grid[i][j] = working_grid[i][j] = MAXN;
  while( cin >> n >> r >> c >> k, n ){
    for( int i = 1; i <= r; ++ i )
      for( int j = 1; j <= c; ++ j ){
	cin >> grid[i][j];
	working_grid[i][j] = grid[i][j];
      }
    for( int i = 0; i < k; ++ i )
      battle();
    for( int i = 1; i <= r; ++ i )
      for( int j = 1; j <= c; ++ j )
	cout << grid[i][j] << (j == c ? '\n' : ' ');
  }
  return 0;
}
