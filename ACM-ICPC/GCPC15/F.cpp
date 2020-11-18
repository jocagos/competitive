#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 1000000, MAXP = 78498;
using ull = unsigned long long;
bool sieve[MAXN]{}; // Check list
vector<unsigned long long> primes(MAXP);
int pidx {};

bool is_prime( ull n ){
  if( n < MAXN ) return sieve[n];
  else{
    if( n % 2 == 0 ) return false;
    bool ans = true;
    for( int i = 1; i < (int)primes.size() and ans; ++ i ){
      if( primes[i] * primes[i] > n ) break;
      if( n % primes[i] == 0 ) ans = false;
    }
    return ans;
  }
}

void atkin(){
  if (MAXN > 2)
    primes[pidx ++] = 2ULL;
  if (MAXN > 3)
    primes[pidx ++] = 3ULL;

  for (int i = 0; i < MAXN; i++)
    sieve[i] = false;

  for (ull x = 1; x * x < MAXN; x++) {
    for (ull y = 1; y * y < MAXN; y++) {
      ull n = (4ULL * x * x) + (y * y);
      if (n <= MAXN && (n % 12ULL == 1ULL || n % 12ULL == 5ULL))
	sieve[n] ^= true;
      n = (3ULL * x * x) + (y * y);
      if (n <= MAXN && n % 12ULL == 7ULL)
	sieve[n] ^= true;
      n = (3ULL * x * x) - (y * y);
      if (x > y && n <= MAXN && n % 12ULL == 11ULL)
	sieve[n] ^= true;
    }
  }
  for (int r = 5; r * r < MAXN; r++) {
    if (sieve[r])
      for (int i = r * r; i < MAXN; i += r * r)
	sieve[i] = false;
  }

  for (int a = 5; a < MAXN; a++)
    if (sieve[a])
      primes[pidx ++] = a;
}

int main(){
  atkin();
  unsigned long long N {};
  cin >> N;
  unsigned long long ans = 1;
  
  for( auto& p : primes ){
    if( p * p * p > N )
      break;
    int cnt = 1;
    while( N % p == 0ULL ){
      N /= p;
      ++ cnt;
    }
    ans *= cnt;
  }
  ull r = ull(sqrt(N));
  if( is_prime( N ) )
    ans *= 2;
  else if( r * r == N and sieve[r] )
    ans *= 3;
  else if( N != 1ULL )
    ans *= 4;
  cout << ans << '\n';
  return 0;
}
