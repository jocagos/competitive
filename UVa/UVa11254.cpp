#include <bits/stdc++.h>

using namespace std;
constexpr long long MAXN = 1e9;
constexpr int MAXARR = sqrt(MAXN) + 10;
long long su[MAXARR] {};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // init
  for( int i = 1; i < MAXARR; ++ i )
    su[i] = su[i - 1] + i;
  
  return 0;
}
