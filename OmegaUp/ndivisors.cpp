#include <bits/stdc++.h>
#define MAXN 1000000
using namespace std;

bool sieve[MAXN]; // Check list
vector<int> primes;

int atkin(){
  if (MAXN > 2)
    primes.push_back(2);
  if (MAXN > 3)
    primes.push_back(3);

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
      primes.push_back(a);
}

map<long, long long> divisors;

int main(){
  atkin();
  long long N, sum = 0;
  cin >> N;
  if( N >= 1 ) sum++;
  for( int i = 2; i <= N; ++ i ){
    int t = i;
    for( auto x : primes ){
      if( x > i ) break;
      while( t > 1 and t % x == 0 ) t /= x, divisors[x]++;
    }
  }
  for( auto x : divisors ) sum *= x.second + 1, sum %= 98765431;
  cout << sum << endl;
  return 0;
}
