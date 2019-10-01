#include <bits/stdc++.h>

using namespace std;

inline long long f( long long n ){
  return floor( (-3. + sqrt( 1 + 8 * n ))/2 ) + 1;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q {};
  cin >> q;
  while( q -- ){
    long long n {};
    cin >> n;
    long long k = f( n );
    cout << n - k << '\n';
  }
  return 0;
}
