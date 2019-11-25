#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n {};
  while( cin >> n, n ){
    long long bits = ceil( log2( n + 1 ) );
    cout << "The parity of " << bitset<64>( n ).to_string().substr( 64 - bits ) << " is " << __builtin_popcountll( n ) << " (mod 2).\n";
  }
  return 0;
}
