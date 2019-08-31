#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main(){
  int t;
  scanf("%d", &t);
  while( t -- ){
    int d, p, grid[1026][1026];
    memset( grid, 0, sizeof grid );
    scanf("%d", &d);
    scanf("%d", &p);
    while( p -- ){
      int x, y, val;
      scanf("%d %d %d", &x, &y, &val);
      for( int i = (x-d < 0 ? 0 : x-d); 0 <= i and i < 1024 and i <= x + d; ++ i ){
	for( int j = (y-d < 0 ? 0 : y-d); 0 <= j and j < 1024 and j <= y + d; ++ j ){
	  grid[i][j] += val;
	}
      }
    }
    int max = 0, maxX = 0, maxY = 0;
    for( int i = 0; i < 1024; ++ i ){
      for( int j = 0; j < 1024; ++ j ){
	if( grid[i][j] > max ) max = grid[i][j], (maxX = i, maxY = j);
      }	
    }
    cout << maxX << " " << maxY << " " << max << endl;
  }
  return 0;
}
