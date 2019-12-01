#include <bits/stdc++.h>

using namespace std;

unordered_map<string, vector<vector<int>>> memo;

set<int> primes { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };

bool is_valid( vector<int>& a ){
  for( unsigned i = 0; i < a.size(); ++ i ){
    if( primes.find( a[i] + a[(i + 1) % a.size()] ) == primes.end() )
      return false;
  }
  return true;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, TC {};
  while( cin >> n ){
    if( TC ) cout << '\n';
    cout << "Case " << ++ TC << ":\n";
    vector<int> a( n, 1 );
    for( int i = 1; i < n; ++ i ) a[i] = a[i - 1] + 1;
    string s;
    for( int i = 0; i < n; ++ i ) s += to_string( a[i] );
    if( memo.find( s ) == memo.end() ){ // generate
      memo[s]; // initialize the vector
      do{
	if( is_valid( a ) )
	  memo[s].push_back( a );
      } while( next_permutation( begin( a ), end( a ) ) );
    }
    for( auto cont : memo[s] )
      for( unsigned i = 0; i < cont.size(); ++ i )
	cout << cont[i] << (i + 1 < cont.size() ? ' ' : '\n');
  }
  return 0;
}
