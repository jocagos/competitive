#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 55;
int mat[MAXN][MAXN];
int n, m;

bool check( int x, int y ){
  if( mat[x][y] == 0 ) return true;
  bool ans = false;
  if( x > 0 and y > 0 )
    ans = ans or (mat[x][y] and mat[x + 1][y + 1] and mat[x + 1][y] and mat[x][y + 1] );
  if( x < n - 1 and y < m - 1 )
    ans = ans or ( mat[x - 1][y - 1] and mat[x - 1][y] and mat[x][y - 1] and mat[x][y] );
  if( x > 0 and y < m - 1 )
    ans = ans or ( mat[x - 1][y] and mat[x - 1][y + 1] and mat[x][y] and mat[x][y + 1] );
  if( x < n - 1 and y > 0 )
    ans = ans or ( mat[x][y - 1] and mat[x][y] and mat[x + 1][y - 1] and mat[x + 1][y] );
  return ans;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for( int i = 0; i < n; ++ i )
    for( int j = 0; j < m; ++ j )
      cin >> mat[i][j];
  bool able = true;
  for( int i = 0; i < n - 1 and able; ++ i )
    for( int j = 0; j < m - 1 and able; ++ j ){
      if( check( i, j ) ) mat[i][j] = 2;
      else able = false;
    }
  if( able ){
    int c = 0;
    vector<tuple<int, int>> pos {};
    for( int i = 0; i < n - 1; ++ i ){
      for( int j = 0; j < m - 1; ++ j ){
	if( mat[i][j] == 2 ){
	  pos.emplace_back( i, j );
	  c ++;
	  mat[i][j] = mat[i + 1][j] = mat[i][j + 1] = mat[i + 1][j + 1] = 0;
	}
      }
    }
    cout << c << "\n";
    for( auto t : pos ) cout << get<0>( t ) << " " << get<1>( t ) << "\n";
  }
  else cout << "-1\n";
  return 0;
}
