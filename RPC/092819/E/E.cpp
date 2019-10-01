#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t {};
  cin >> t;
  while( t -- ){
    int n {}, p {};
    cin >> n >> p;
    // if( p ){ // casino begins
    //   if( n % 3 == 0 ) cout << "1\n";
    //   else cout << "0\n";
    // }
    // else{ // santiago begins
    //   if( n % 3 == 0 ) cout << "0\n";
    //   else cout << "1\n";
    // }
    if( p ) cout << "0\n";
    else cout << "1\n";
  }
  return 0;
}
