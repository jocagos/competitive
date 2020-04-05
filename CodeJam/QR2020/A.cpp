#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  constexpr int MAX_SIZE = 110;
  int mat[MAX_SIZE][MAX_SIZE] {};
  for( int CASE = 1; CASE <= tc; ++ CASE ){
    int n {};
    cin >> n;
    int TRACE {}, ROWS {}, COLS {};
    for( int i = 0; i < n; ++ i ){
      for( int j = 0; j < n; ++ j )
	cin >> mat[i][j];
      TRACE += mat[i][i];
    }
    for( int i = 0; i < n; ++ i ){
      int cnt[MAX_SIZE] {};
      for( int j = 0; j < n; ++ j ){
	cnt[mat[i][j]] ++;
	if( cnt[mat[i][j]] > 1 ){
	  ++ ROWS;
	  break;
	}
      }
    }
    for( int i = 0; i < n; ++ i ){
      int cnt[MAX_SIZE] {};
      for( int j = 0; j < n; ++ j ){
	cnt[mat[j][i]] ++;
	if( cnt[mat[j][i]] > 1 ){
	  ++ COLS;
	  break;
	}
      }
    }
    cout << "Case #" << CASE << ": " << TRACE << " " << ROWS << " " << COLS << endl;
  }
  return 0;
}
