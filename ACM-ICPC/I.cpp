#include <iostream>

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
      if( '0' <= lhs[j] and lhs[h] <= '9' ){
	cnt += lhs[j] - '0';
	++ j;
      }
      else
	++ cnt;
    }
    if( cnt > k ) cout << "unfeasible\n";
    else{ // build the string
      for( int j = 0; j < lhs.length(); ++ j ){
	if( '0' <= lhs[j] and lhs[h] <= '9' ){
	  for( int r = 0; r < lhs[j] - '0'; ++ r )
	    cout << lhs[j + 1];
	  ++ j;
	}
	else{
	  cout << lhs[j];
	}
      }
      cout << '\n';
    }
  }
  return 0;
}
