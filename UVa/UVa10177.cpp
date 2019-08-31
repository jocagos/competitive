#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  while( cin >> n ){
    long long a = n * (n + 1) * (2 * n + 1 ) / 6,
      b = (n + 1) * n / 2 * (n + 1) * n / 2,
      c = n * (n + 1) / 2 * n * (n + 1) / 2,
      d = n * (n + 1) / 2 * n * (n + 1) / 2 * (n + 1) * n / 2,
      e = 0,
      f = 0;
    for( int i = 1; i <= n; ++ i ) e += i * i * i * i;
    f = (n + 1) * n / 2 * (n + 1) * n / 2 * (n + 1) * n / 2 * (n + 1) * n / 2 - e;
    b -= a;
    d -= c;
    cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << "\n";
  }
  return 0;
}
