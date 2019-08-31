#include <stdio.h>
#include <math.h>

int a[28];
long long fact[23];

long long f( int n ){
  double half = n / 2.0;
  /* printf("got %d and half is %lf\n", n, half ); */
  /* printf("about to return (%d + %d)/2\n", fact[(int)ceil(half)], fact[(int)half] ); */
  long long a = fact[(int)ceil(half)], b = fact[(int)half];
  
}

int main(){
  fact[0] = 1;
  int n, i = 0;
  for( i = 1; i < 23; ++ i ) fact[i] = fact[i - 1] * i;
  i = 0;
  scanf("%d\n", &n );
  char c;
  for( i; i < n; ++ i ){
    scanf("%c%*s\n", &c);
    /* printf("scanned: %c\n", c ); */
    a[c - 'a'] ++;
  }
  /* for( i = 0; i < 28; ++ i ) printf("%c : [ %d, %d ]\n", 'a' + i, a[i], b[i] ); */
  long long ans = 0;
  for( i = 0; i <= 'z' - 'a'; ++ i ) ans += f( a[i] );
  ans >>= 1;
  printf("%d\n", ans );
  return 0;
}
