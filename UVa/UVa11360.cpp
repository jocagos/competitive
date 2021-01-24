#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
constexpr int MAXN = 11;
int n {}, q {};
int y_idx[MAXN] {}, x_idx[MAXN] {};
char mat[MAXN][MAXN] {};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string line {};
  int tc {};
  cin >> tc;
  for( int CASE = 1; CASE <= tc; ++ CASE ){
    bool transpose {};
    int increment {};
    cout << "Case #" << CASE << '\n';
    cin >> n;
    for( int i = 0; i < n; ++ i ){
      cin >> mat[i];
      y_idx[i] = x_idx[i] = i;
      for( int j = 0; j < n; ++ j )
	mat[i][j] -= '0';
    }
    cin >> q;
    string query;
    while( q -- ){
      cin >> query;
      int a {}, b {};
      // cerr << "QUERY: >" << query << "<\n";
      if( query[0] == 'r' ){ // row
	cin >> a >> b;
	-- a; -- b;
	if( transpose )
	  swap( x_idx[a], x_idx[b] );
	else
	  swap( y_idx[a], y_idx[b] );
      }
      else if( query[0] == 'c' ){ // col
	cin >> a >> b;
	-- a; -- b;
	if( transpose )
	  swap( y_idx[a], y_idx[b] );
	else
	  swap( x_idx[a], x_idx[b] );
      }
      else if( query[0] == 't' ) // transpose
	transpose = (not transpose);
      else if( query[0] == 'i' ) // inc
	++ increment;
      else if( query[0] == 'd' ) // dec
	-- increment;
      // cerr << "a: " << a << "\tb: " << b << '\n';
      // for( int i = 0; i < n; ++ i )
      // 	cerr << "x[" << i << "] = " << x_idx[i] << '\n';
      // for( int i = 0; i < n; ++ i )
      // 	cerr << "y[" << i << "] = " << y_idx[i] << '\n';
    }
    // after all the queries, perform the changes:
    if( increment != 0 )
      for( int i = 0; i < n; ++ i )
	for( int j = 0; j < n; ++ j )
	  mat[i][j] = (mat[i][j] + 10 + increment) % 10;
    auto X = (transpose ? y_idx : x_idx );
    auto Y = (transpose ? x_idx : y_idx );
    for( int i = 0; i < n; ++ i ){
      for( int j = 0; j < n; ++ j ){
	if( transpose )
	  cout << (int)(mat[X[j]][Y[i]]);
	else
	  cout << (int)(mat[Y[i]][X[j]]);
      }
      cout << '\n';
    }
    cout << '\n';
  }
  return 0;
}
