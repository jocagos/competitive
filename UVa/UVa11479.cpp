#include <iostream>

using namespace std;

int main(){
  int n;
  scanf("%d", &n);
  for( int i = 1; i <= n; ++i ){
    long long a, b, c;
    cout << "Case " << i << ": ";
    scanf("%lld %lld %lld", &a, &b, &c);
    if( a <= 0 or b <= 0 or c <= 0 ) cout << "Invalid";
    else if( a + b <= c or a + c <= b or b + c <= a ) cout << "Invalid";
    else if( a == b and b == c ) cout << "Equilateral";
    else if( a == b or a == c or b == c ) cout << "Isosceles";
    else cout << "Scalene";
    cout << endl;
  }
  return 0;
}
