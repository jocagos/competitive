#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1010;
bool is_prime[MAXN] {};
vector<int> primes;

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
  memset( is_prime, true, sizeof is_prime );
  is_prime[0] = is_prime[1] = false;
  for( int i = 2; i < MAXN; ++ i ){
    if( is_prime[i] ){
      for( int j = 2; j * i < MAXN; ++ j )
	is_prime[i * j] = false;
      primes.emplace_back( i );
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
  vector<int> ns( N + 1 );
  for( int i = 0; i < N; ++ i )
    cin >> ns[i];
  vector<int> ms( M );
  vector<tuple<int, int, int>> edges( K );
  int mat[110][110] {};
  vector<int> freq( 110, 0 );
  for( int i = 0; i < K; ++ i ){
    auto& [a, b, c] = edges[i];
    cin >> a >> b >> c;
    if( is_prime[b] and c == 1 )
      ns[a] = b;
    else if( ns[a] == 0 ){
      int i = 0;
      while( b % pf[i] != 0 ) ++ i;
      
    }
    mat[a][b] = c;
    freq[b] ++;
  }
  
  sort( edges.begin(), edges.end(), []( auto lhs, auto rhs ) -> bool {
				      auto& [la, lb, lc] = lhs;
				      auto& [ra, rb, rc] = rhs;
				      if( lb != rb ) return lb < rb;
				      else if( la != ra ) return la < ra;
				      else return lc < rc;
				    } );
  
  
  return 0;
}
