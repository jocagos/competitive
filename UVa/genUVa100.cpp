#include <cstdio>
#include <iostream>

using namespace std;

long long a[1000010];

long long f( long long n ){
  if( n == 1 ) return 0;
  long long c = 1;
  while( n != 1 ){
    if( n % 2 ) n = 3 * n + 1;
    else n = n / 2;
    ++ c;
    // if( n <= 1000000 and a[n] != 0 and n != 1 ) return c + a[n];
  }
  return c;
}

int main( void ){
  printf("{ ");
  a[0] = 0;
  for( int i = 1; i <= 1000000; ++ i ){
    // cerr << "at " << i << endl;
    a[i] = f( i );
    printf("%lld, ", a[i] );
    if( i % 100 == 0 ) printf("\n");
  }
  printf("}\n");
  return 0;
}
