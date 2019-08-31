#include <bits/stdc++.h>

using namespace std;

int main(){
  using ay = unsigned long long;
  int q;
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> q;
  ay n;
  while( q -- ){
    cin >> n;
    int times = 0;
    bool able = true;
    while( able and n > 1 ){
      if( n % 2 == 0 ){
	n >>= 1;
	times ++;
      }
      else if( n % 3 == 0 ){
	times ++;
	n /= 3;
	n <<= 1;
      }
      else if( n % 5 == 0 ){
	times ++;
	n /= 5;
	n <<= 2;
      }
      else able = false;
    }
    if( able ) cout << times << '\n';
    else cout << "-1\n";
  }
  return 0;
}
