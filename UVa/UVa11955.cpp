#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 55;
long long memo[MAXN][MAXN] {};

void init(){
  memo[0][0] = 0;
  for( int i = 1; i < MAXN; ++ i ){
     memo[i][0] = 1;
    for( int j = 1; j < i; ++ j )
      memo[i][j] = memo[i - 1][j] + memo[i - 1][j - 1];
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  init();
  string line {};
  getline( cin, line );
  int tc = stoi( line );
  for( int T = 1; T <= tc; ++ T ){
    getline( cin, line );
    int idx_caret = line.find( '^' );
    int idx_plus = line.find( '+' );
    string ex = line.substr( idx_caret + 1 );
    string bas = line.substr( 1, idx_caret - 2 );
    string l = line.substr( 1, idx_plus - 1 );
    string r = line.substr( idx_plus + 1, idx_caret - 2 - idx_plus );
    int idx_pascal = stoi( ex );
    cout << "Case " << T << ": ";
    int lidx = idx_pascal, ridx = 0;
    for( int i = 0; i <= idx_pascal; ++ i ){
      if( i > 0 )
	cout << '+';
      if( memo[idx_pascal + 1][i] > 1 )
	cout <<  memo[idx_pascal + 1][i] << '*';
      if( lidx )
	cout << l;
      if( lidx > 1 )
	cout << '^' << lidx;
      if( lidx and ridx )
	cout << '*';
      if( ridx )
	cout << r;
      if( ridx > 1 )
	cout << '^' << ridx;
      -- lidx;
      ++ ridx;
    }
    cout << '\n';
  }
  return 0;
}
