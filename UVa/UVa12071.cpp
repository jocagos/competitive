#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
constexpr int MAXN = 40040;
int n {};
int arr[MAXN] {};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int CASE {};
  while( cin >> n, n ){
    unordered_map<int, int> vals;
    for( int i = 0; i < n; ++ i )
      cin >> arr[i];
    sort( arr, arr + n );
    long long ans {};
    for( int i = 0; i < n; ++ i ){
      ans += i;
      ans -= (vals[arr[i]]);
      vals[arr[i]] ++;
    }
    cout << "Case " << (++CASE) << ": " << ans << '\n';
  }
  return 0;
}
