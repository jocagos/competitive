#include <bits/stdc++.h>

using namespace std;
using ld2 = pair<long double, long double>;

ld2 f( int a, int b, int c ){
  long double disc = b * b - 4 * a * c;
  if( disc >= 0 ){
    long double s = sqrt( disc );
    long double left, right;
    left = (-b + s) / 2;
    right = (-b - s) / 2;
    return ld2(left, right);
  }
  else return ld2(-1, -1);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while( n -- ){
    int d;
    cin >> d;
    auto p = f( 1, -d, d );
    if( p.first != -1 and p.second != -1 )
      cout << "Y " << setprecision(9) << fixed << p.first << " " << p.second << '\n';
    else cout << "N\n";
  }
  return 0;
}
