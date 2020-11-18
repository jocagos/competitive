#include <iostream>
#include <algorithm>
using namespace std;
int a[5] {};

bool backtrack( int pos, int val ){
  if( pos == 5 )
    if( val == 23 ) return true;
    else return false;
  return backtrack( pos + 1, val + a[pos] ) or
         backtrack( pos + 1, val - a[pos] ) or
         backtrack( pos + 1, val * a[pos] );
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  while( cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] ){
    if( a[0] | a[1] | a[2] | a[3] | a[4] ){
      bool ans = false;
      sort( a, a + 5 );
      do{
	if( backtrack( 1, a[0] ) ){
	  ans = true;
	  break;
	}
      } while( next_permutation( a, a + 5 ) );
      if( ans )
	cout << "Possible\n";
      else
	cout << "Impossible\n";
    }
    else
      exit(0);
  }
  return 0;
}
