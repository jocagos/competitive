#include <bits/stdc++.h>
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
  long long i, j;
  while( scanf("%lld %lld", &i, &j) != EOF ){
    long long m = f(min(i,j));
    for( int k = min(i, j)+1; k <= max(i, j); ++k ){
      long long tmp = f(k);
      if( tmp > m ) m = tmp;
    }
    printf("%lld %lld %lld\n", i, j, m);
  }
  return 0;
}
