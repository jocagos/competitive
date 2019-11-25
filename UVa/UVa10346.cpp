#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // cout.tie(0);
  int n {}, k {};
  while( cin >> n >> k ){
    int N{}, b{};
    while( n ){
      N += n;
      b += n;
      n = b / k;
      b -= n * k;
      if( n == 0 and b < k ) break;
    }
    cout << N << '\n';
  }
  return 0;
}
