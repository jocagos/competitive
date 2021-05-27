#include <iostream>

using namespace std;

inline long long max( long long a, long long b ){
  return (a + b + abs(a - b)) >> 1;
}

constexpr int MAXN = 1000010;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, k {};
  long long ans {};
  long long vals[MAXN] {};
  cin >> n;
  for( int i = 0; i < n; ++ i )
    cin >> vals[i];
  for( int i = 1; i < n; ++ i )
    vals[i] += vals[i - 1];
  cin >> k;
  if( k > n ) k = n;
  if( k ){
    ans = max( ans, vals[k - 1] );
    for( int i = 0; i < n - k; ++ i )
      ans = max( ans, vals[k + i] - vals[i] );
  }
  cout << ans << '\n';
  return 0;
}
