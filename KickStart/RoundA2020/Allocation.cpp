#include <bits/stdc++.h>
using namespace std;

int main(){
  int tc {};
  cin >> tc;
  for( int CASE = 1; CASE <= tc; ++ CASE ){
    long long n {}, b {};
    cin >> n >> b;
    vector<long long> arr( n );
    for( int i = 0; i < n; ++ i )
      cin >> arr[i];
    sort( arr.begin(), arr.end() );
    int cnt = 0;
    while( cnt < arr.size() and b >= arr[cnt] ){
      b -= arr[cnt];
      ++ cnt;
    }
    cout << "Case #" << CASE << ": " << cnt << endl;
  }
  return 0;
}
