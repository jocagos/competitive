#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n {};
  bool down = true;
  cin >> n;
  vector<int> a( n );
  for( int i = 0; i < n; ++ i ){
    cin >> a[i];
    if( a[i] % 2 == 0 ) a[i] >>= 1;
    else{
      a[i] >>= 1;
      if( down ) down = false;
      else{
	down = true;
	a[i] ++;
      }
    }
  }
  for( int i = 0; i < n; ++ i ) cout << a[i] << ( i + 1 == n ? "\n" : " " );
  return 0;
}
