#include <bits/stdc++.h>
constexpr int MAXN = 1000100, MAXP = 78498;
using namespace std;

bool sieve[MAXN]{}; // Check list
vector<int> primes(MAXP);
int pidx {};

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

bool is_prime( int n ){
  if( n < MAXN ) return sieve[n];
  bool is = true;
  for( auto p : primes ){
    if( p > sqrt(n) )
      break;
    if( n % p == 0 ){
      is = false;
      break;
    }
  }
  return is;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  atkin();
  int n {};
  while( cin >> n ){
    if( is_prime( n ) ){
      string s = to_string( n );
      string t( s.rbegin(), s.rend() );
      int m = stoi( t );
      if( is_prime( m ) and m != n ) cout << n << " is emirp.\n";
      else cout << n << " is prime.\n";
    }
    else cout << n << " is not prime.\n";
  }
  return 0;
}
