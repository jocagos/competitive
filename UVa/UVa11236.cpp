#include <iostream>

using namespace std;

int main(){
  long long a, b, c, d;
  for( a = 1; a + a + a + a<= 2000; a ++ ){
    for( b = a; a + b + b + b <= 2000; b ++ ){
      for( c = b; a + b + c + c <= 2000; c ++ ){
	long long p = a * b * c, s = a + b + c;
	if( p <= 1000000 or (s * 1000000) % (p - 1000000) ) continue;
	d = (s * 1000000) / (p - 1000000);
	s += d;
	if( s > 2000 or d < c ) continue;
	printf("%d.%02d %d.%02d %d.%02d %d.%02d\n", a / 100, a % 100, b / 100, b % 100, c / 100, c % 100, d / 100, d % 100 );
      }
    }
  }
  return 0;
}
