#include <bits/stdc++.h>

using namespace std;

inline long long f( long long n, long long m, long long c ){
  n -= 7;
  m -= 7;
  long long ans = n * m;
  if( c == 0 ){
    return ans / 2;
  }
  else{
    return (ans + 1) / 2;
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m, c;
  while( cin >> n >> m >> c, n | m | c ){
    cout << f( n, m, c ) << '\n';
  }
  return 0;
}
