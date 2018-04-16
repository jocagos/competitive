#include <iostream>
#include <algorithm>
using namespace std;

long long f( long long n ){
  long long c = 1;
  while( n != 1 ){
    if( n % 2 ) n = 3 * n + 1;
    else n = n / 2;
    c++;
  }
  return c;
}

int main(){
  long long i, j, v[10000];
  for( i = 1; i < 10000; ++i ) v[i] = f(i);
  while( scanf("%lld %lld", &i, &j) != EOF ){
    long long m = 0;
    for( int k = min(i, j); k <= max(i,j); ++k ){
      long long tmp = f(k);
      if( tmp > m ) m = tmp;
    }
    cout << i << " " << j << " " << m << endl;
  }
  return 0;
}
