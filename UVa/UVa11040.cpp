#include <iostream>

using namespace std;
constexpr int MAXN = 10;
int row_max[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int mat[MAXN][MAXN] {};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tmp {}, tc {};
  cin >> tc;
  while( tc -- ){
    for( int i = 0; i < 5; ++ i )
      for( int j = 0; j <= i; ++ j )
	cin >> mat[2 * i][2 * j];
    // compute the bases
    mat[8][1] = (mat[6][0] - mat[8][0] - mat[8][2]) / 2;
    mat[8][3] = (mat[6][2] - mat[8][2] - mat[8][4]) / 2;
    mat[8][5] = (mat[6][4] - mat[8][4] - mat[8][6]) / 2;
    mat[8][7] = (mat[6][6] - mat[8][6] - mat[8][8]) / 2;
    // compute all the blocks
    for( int i = 7; i >= 0; -- i ) // row
      for( int j = 0; j <= i; ++ j ) // column
	mat[i][j] = mat[i + 1][j] + mat[i + 1][j + 1];
    // print them out
    for( int i = 0; i < 9; ++ i )
      for( int j = 0; j < row_max[i]; ++ j )
	cout << mat[i][j] << (j + 1 == row_max[i] ? '\n' : ' ');
  }
  return 0;
}
