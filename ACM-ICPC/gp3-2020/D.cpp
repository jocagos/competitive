#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  string lhs {}, rhs {};
  cin >> n;
  for( int i = 0; i < n; ++ i ){
    int k {};
    cin >> lhs >> k;
    int cnt {};
    for( int j = 0; j < lhs.length(); ++ j ){
      int idx = j;
      if( '0' <= lhs[j] and lhs[j] <= '9' ){
	while( idx < lhs.length() and ('0' <= lhs[idx] and lhs[idx] <= '9') ) ++ idx;
	cnt += stoll( lhs.substr( j, idx - j ) );
	j = idx;
      }
      else
	++ cnt;
    }
    if( cnt > k ) cout << "unfeasible\n";
    else{ // build the string
      for( int j = 0; j < lhs.length(); ++ j ){
	// get the number
	int idx = j;
	if( '0' <= lhs[j] and lhs[j] <= '9' ){
	  while( idx < lhs.length() and ('0' <= lhs[idx] and lhs[idx] <= '9') ) ++ idx;
	  long long reps = stoll( lhs.substr( j, idx - j ) );
	  j = idx;
	  while( reps -- ) cout << lhs[idx];
	}
	else
	  cout << lhs[j];
      }
      cout << '\n';
    }
  }
  return 0;
}
