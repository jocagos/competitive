#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1010;
bool is_prime[MAXN] {};
set<int> primes;

int bin_pow( int a, int b ){
  int res = 1;
  while( b > 0 ){
    if( b & 1 ) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}

void sieve(){
  for( int i = 2; i < MAXN; ++ i )
    is_prime[i] = true;
  for( int i = 2; i < MAXN; ++ i ){
    if( is_prime[i] ){
      for( int j = 2; j * i < MAXN; ++ j )
	is_prime[i * j] = false;
      primes.emplace( i );
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  sieve();
  int M {}, N {}, K {};
  cin >> M >> N >> K;
  vector<int> ns( N, 0 );
  set<int> ms;
  for( int i = 0; i < N; ++ i ){
    cin >> ns[i];
    if( is_prime[ns[i]] )
      ms.emplace( ns[i] );
  }
  for( int i = 0; i < N; ++ i ){
    for( auto& p : primes ){
      if( p > ns[i] ) continue;
      if( ns[i] % p == 0 ){
	int q = ns[i] / p;
	if( is_prime[q] )
	  ms.emplace( q );
	ms.emplace( p );
      }
    }
  }  
  for( int i = 0; i < K; ++ i ){
    int a, b, c;
    cin >> a >> b >> c;      
  }
  int i = 0;
  for( auto& x : ms ){
    cout << x << ( i + 1 == int(ms.size()) ? '\n' : ' ' );
    ++ i;
  }
  return 0;
}
