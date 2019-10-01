#include <bits/stdc++.h>
constexpr int MAXP = 1000000;
constexpr int MAXN = 505;
using namespace std;

bool sieve[MAXP]; // Check list
vector<int> primes;

void atkin(){
  if (MAXP > 2)
    primes.emplace_back(2);
  if (MAXP > 3)
    primes.emplace_back(3);

  for (int i = 0; i < MAXP; i++)
    sieve[i] = false;

  for (int x = 1; x * x < MAXP; x++) {
    for (int y = 1; y * y < MAXP; y++) {
      int n = (4 * x * x) + (y * y);
      if (n <= MAXP && (n % 12 == 1 || n % 12 == 5))
	sieve[n] ^= true;
      n = (3 * x * x) + (y * y);
      if (n <= MAXP && n % 12 == 7)
	sieve[n] ^= true;
      n = (3 * x * x) - (y * y);
      if (x > y && n <= MAXP && n % 12 == 11)
	sieve[n] ^= true;
    }
  }
  for (int r = 5; r * r < MAXP; r++) {
    if (sieve[r])
      for (int i = r * r; i < MAXP; i += r * r)
	sieve[i] = false;
  }

  for (int a = 5; a < MAXP; a++)
    if (sieve[a])
      primes.emplace_back(a);
}

int next_prime( int n ){
  auto it = lower_bound( begin( primes ), end( primes ), n );
  if( it != end( primes ) ) return *it;
  else return -1;
}

int main()
{
  atkin();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, m {}, tmp {};;
  int mat[MAXN][MAXN] {};
  cin >> n >> m;
  for( int i = 0; i < n; ++ i ){
    for( int j = 0; j < m; ++ j ){
      cin >> tmp;
      mat[i][j] = next_prime( tmp ) - tmp;
    }
  }
  int s[MAXN] {}, t[MAXN] {};
  for( int i = 0; i < n; ++ i ){
    for( int j = 0; j < m; ++ j ){
      s[i] += mat[i][j];
    }
  }
  for( int i = 0; i < m; ++ i ){
    for( int j = 0; j < n; ++ j ){
      t[i] += mat[j][i];
    }
  }
  cout << min( *min_element( s, s + n ), *min_element( t, t + m ) ) << endl;
  return 0;
}
