#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
  ll a, b;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  while( cin >> a >> b ){
    if( b > a ) cout << (b-a) << '\n';
    else cout << (a-b) << '\n';
  }
  return 0;
}
