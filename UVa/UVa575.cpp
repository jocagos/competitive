#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string line {};
  while( getline( cin, line ), line != "0" ){
    long long ans = 0;
    long long p = 2;
    for( auto it = line.rbegin(); it != line.rend(); ++ it ){
      ans += (*it - '0') * (p - 1);
      p <<= 1;
    }
    cout << ans << '\n';
  }
  return 0;
}
