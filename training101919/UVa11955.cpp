#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 55;
long long memo[MAXN][MAXN] {};
vector<vector<int>> pascal( MAXN );

void init(){
  for( int i = 0; i < MAXN; ++ i ) memo[i][0] = 1;
  for( int i = 1; i < MAXN; ++ i )
    for( int j = i; j < MAXN; ++ j )
      memo[j][i] = memo[j - 1][i - 1] + memo[j - 1][i];
  for( int i = 0; i < MAXN; ++ i )
    for( int j = 0; j < MAXN; ++ j ){
      if( memo[i][j] > 0 ) 
	pascal[i].emplace_back( memo[i][j] );
      else break;
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
    for( unsigned i = 0; i < pascal[idx_pascal].size(); ++ i ){
      bool le = false;
      bool coeff = false;
      if( i > 0 ) cout << '+';
      if( i < pascal[idx_pascal].size() - 1 ){ // we need to include l
	if( pascal[idx_pascal][i] > 1 ){// coeff > 1
	  cout << pascal[idx_pascal][i] << '*';
	  coeff = true;
	}
	cout << l;
	if( idx_pascal - i > 1 ) cout << '^' << idx_pascal - i;
	le = true;
      }
      if( i > 0 ){ // we need to print r
	if( le ) cout << '*';
	if( pascal[idx_pascal][i] > 1 and not coeff ){
	  cout << pascal[idx_pascal][i] << '*';
	  coeff = true;
	}
	cout << r;
	if( i > 1 ) cout << '^' << i;
      }
    }
    cout << '\n';
    
  }
  return 0;
}
