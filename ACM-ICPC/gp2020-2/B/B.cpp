#include <bits/stdc++.h>

using namespace std;
const int UNSET = -1;

int grid[11][11] {};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N {};
  cin >> N;
  char ans = 'Y';
  for( int idx = 1; idx <= N; ++ idx ){
    memset( grid, UNSET, sizeof grid );
    int dir {}, len {}, row {}, col {};
    cin >> dir >> len >> row >> col;
    if( dir == 0 ){ // horizontally, then we add to COL
      // check bounds for each position, if it isn't valid just make ans = 'N' and break
      // otherwise keep going
      // fill (row, col), ..., (row, col + len - 1) with idx
      // if it is already set with another number distinct to UNSET, just make ans = 'N' and break
      
    }
    else{ // vertically, then we add to ROW
      // same procedure but for (row, col), ... (row + len - 1, col)
    }
    cout << ans << '\n';
  }
  return 0;
}
