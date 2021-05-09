#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <algorithm>

using namespace std;
constexpr int MAXN = 1000000, MAXP = 78498;

bool sieve[MAXN]{}; // Check list
vector<int> primes(MAXP);
int pidx {};

int gcd( int a, int b ){
  while( b ){
    a %= b;
    swap( a, b );
  }
  return a;
}

bool is_prime( int n ){
  if( n < MAXN )
    return sieve[n];
  else{
    int M = ceil(sqrt(n));
    bool pr = true;
    for( int i = 0; pr and i < pidx and primes[i] <= M; ++ i )
      if( n % primes[i] == 0 )
	pr = false;
    return pr;
  }
}

void atkin(){
  if (MAXN > 2)
    primes[pidx ++] = 2;
  if (MAXN > 3)
    primes[pidx ++] = 3;

  for (int i = 0; i < MAXN; i++)
    sieve[i] = false;

  for (int x = 1; x * x < MAXN; x++) {
    for (int y = 1; y * y < MAXN; y++) {
      int n = (4 * x * x) + (y * y);
      if (n <= MAXN && (n % 12 == 1 || n % 12 == 5))
	sieve[n] ^= true;
      n = (3 * x * x) + (y * y);
      if (n <= MAXN && n % 12 == 7)
	sieve[n] ^= true;
      n = (3 * x * x) - (y * y);
      if (x > y && n <= MAXN && n % 12 == 11)
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

unordered_set<int> prime_factors( int n ){
  unordered_set<int> factors;
  for( int i = 0; (i < pidx and (primes[i] * primes[i] <= n)); ++ i ){
    if( n % primes[i] == 0 ){
      factors.emplace( primes[i] );
      while( n % primes[i] == 0 )
	n /= primes[i];
    }
  }
  if( n != 1 )
    factors.emplace( n );
  return std::move( factors );
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  atkin();
  int tc {};
  cin >> tc;
  while( tc -- ){
    int a {}, b {};
    cin >> a >> b;
    if( a > b ) swap( a, b );
    int cnt {};
    if( a != 1 and b != 1 ){
      unordered_set<int> fac_a = prime_factors( a );
      unordered_set<int> fac_b = prime_factors( b );
      for( auto x : fac_a )
	fac_b.emplace( x );
      cnt = fac_b.size();
    }
    else{
      if( a == 1 and b == 1 )
	cnt = 0;
      else if( a == 1 ){
	unordered_set<int> fac_b = prime_factors( b );
	cnt = fac_b.size();
      }
    }
    cout << cnt << '\n';
  }
  return 0;
}
