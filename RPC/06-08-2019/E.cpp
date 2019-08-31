#include <bits/stdc++.h>

using namespace std;
using nword = unsigned long long;
int f[1000];

int main(){
  string line;
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  while( getline( cin, line ) ){
    memset( f, 0, sizeof f );
    int l = line.length();
    for( int i = 0; i < l; ++ i ) f[line[i] - '0'] ++;
    nword ans = 1;
    for( int i = 0; i <= 4; ++ i ) ans *= (f[i] + 1);
    cout << ans << '\n';
  }
  return 0;
}
