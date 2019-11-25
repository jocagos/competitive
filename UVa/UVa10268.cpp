#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string line1, line2;
  while( getline( cin, line1 ) ){
    getline( cin, line2 );
    vector<long long> coeffs;
    int x = stoi( line1 ), a;
    istringstream iss( line2 );
    while( iss >> a ) coeffs.emplace_back( a );     
    int n = coeffs.size();
    for( int i = 0; i < n; ++ i )
      coeffs[i] *= (n - i - 1);
    coeffs.pop_back();
    long long ans = 0, p = 1;
    p = 1, ans = 0;
    for( auto it = coeffs.rbegin(); it != coeffs.rend(); ++ it ){
      ans += p * (*it);
      p *= x;
    }
    cout << ans << "\n";
  }
  return 0;
}
