#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string line1, line2;
  while( getline( cin, line1 ) ){
    getline( cin, line2 );
    vector<int> coeffs, x;
    istringstream iss1( line1 ), iss2( line2 );
    int a;
    while( iss1 >> a ) coeffs.emplace_back( a );
    while( iss2 >> a ) x.emplace_back( a );
    
    int n = coeffs.size(), m = x.size();
    long long ans = 0, p = 1;
    for( int i = 0; i < m; ++ i ){
      p = 1, ans = 0;
      for( int j = 0; j < n; ++ j ){
	ans += p * coeffs[n - 1 - j];
	p *= x[i];
      }
      cout << ans << (i + 1 == m ? "\n" : " ");
    }
  }
  return 0;
}
