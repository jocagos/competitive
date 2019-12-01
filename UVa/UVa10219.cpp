#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n {}, k {};
  while( cin >> n >> k ){
    long double s {};
    for( long long i = 0; i < k; ++ i )
      s += log10( n - i );
    for( long long i = 1; i <= k; ++ i )
      s -= log10( i );
    cout << (int)(floor(s) + 1) << '\n';
  }
  return 0;
}
