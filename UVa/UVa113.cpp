#include <iostream>
#include <cmath>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  using ull = unsigned long long;
  ull n {}, p {};
  while( cin >> n >> p ){
    ull ans {};
    while( p > 1 ){
      p /= n;
      ++ ans;
    }
    cout << ans << '\n';
  }
  return 0;
}
