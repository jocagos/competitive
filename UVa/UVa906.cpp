#include <bits/stdc++.h>

using namespace std;
constexpr long MAXN = 1000100;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long a, b;
  double eps;
  long long c, d;
  while( cin >> a >> b ){
    cin >> eps;
    long double LEFT = 1.0 * a / b, RIGHT;
    for( d = 1; ; ++ d ){
      c = LEFT * d;
      while( a * d >= b * c ) c ++;
      RIGHT = 1.0L * c / d;
      if( RIGHT - LEFT <= eps ){
	cout << c << " " << d << "\n";
	break;
      }
    }
  }
  return 0;
}
