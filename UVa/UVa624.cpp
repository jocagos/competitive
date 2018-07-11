#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
/* look, a ; */

using namespace std;

vector<int> tracks(20);
bitset<20> check, doubleCheck;

int n, t, ans = 0;

void backtrack( int used ){
  if( used == t ){
    int s = 0;
    for( int i = 0; i < t; ++ i ) if( check[i] ) s += tracks[i];
    if( s <= n ){
      if( ans < s ){
	ans = max( ans, s );
	for( int i = 0; i < n; ++ i ) doubleCheck[i] = check[i];
      }
    }
    return;
  }
  check[used] = 1;
  backtrack( used + 1 );
  check[used] = 0;
  backtrack( used + 1 );
}

int main(){
  while( cin >> n ){
    cin >> t;
    ans = 0; check.reset(), doubleCheck.reset();
    for( int i = 0; i < t; ++ i ) cin >> tracks[i];
    backtrack(0);
    for( int i = 0; i < t; ++ i ) if( doubleCheck[i] ) cout << tracks[i] << " ";
    cout << "sum:" << ans << endl;
  }
  return 0;
}
