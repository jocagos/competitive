#include <bits/stdc++.h>

using namespace std;

int main(){
  int a, b, tc, ans = 0;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> tc;
  long double c2(log10( 2 )), c5(log10(5)); // 2^a * 5^b = log10( 2^a * 5^b ) = log10( 2^a ) + log10( 5^b ) = a * log10( 2 ) + b * log10( 5 )
  while( tc -- ){
    cin >> a >> b;
    ans = ceil( a * c2 + b * c5 );
    cout << ( a == b and b == 0 ? 1 : ans ) << '\n';
  }
  return 0;
}

/*
  log( p^q * r^s );
  log( p^q ) + log( r^s );
  q * log( p ) + s * log( r );
 */

/* 
a^n = a * a ... * a // n times
a^n = a^(n/2) * a^(n/2)
 */
