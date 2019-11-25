#include <bits/stdc++.h>
constexpr int MAXN = 5000005, MAXM = 1000001;
using namespace std;
int n;
int left[MAXM], right[MAXM], memo[MAXN];
long long ans[MAXN];

void sieve_and_compute(){
  for( int i = 2; i < MAXN; ++ i ){
    if( memo[i] ) continue;
    memo[i] = 1;
    for( int j = 2; i * j < MAXN; ++ j ){
      int n = j * i;
      while( n % i == 0 ){
	n /= i;
	memo[i * j] ++;
      }
    }
  }
}

int main(){
  // using namespace chrono;
  // auto _start = high_resolution_clock::now();
  sieve_and_compute();
  for( int i = 2; i < MAXN; ++ i ) ans[i] = ans[i - 1] + memo[i];
  int n;
  scanf("%d\n", &n);
  while( n -- ){
    int a, b;
    scanf("%d %d\n", &a, &b);
    printf("%lld\n", ans[a] - ans[b]);
  }
  // auto _end = high_resolution_clock::now();
  // fprintf( stderr, "Took %ld ns.\n", duration_cast<nanoseconds>( _end - _start ).count() );
  return 0;
}
