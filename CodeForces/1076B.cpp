#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef pair<ii, int> tern;
typedef pair<ii, ii> quad;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<tern> vtern;
typedef vector<quad> vquad;
// minHeap, BinomialHeap and FibonacciHeap for later use, policy based data structures
template <class T> using minHeap = __gnu_pbds::priority_queue<T, greater<T>, pairing_heap_tag>;
template <class T> using minBinHeap = __gnu_pbds::priority_queue<T, greater<T>, rc_binomial_heap_tag>;
template <class T> using minFHeap = __gnu_pbds::priority_queue<T, greater<T>, thin_heap_tag>;
template <class T> using maxFHeap = __gnu_pbds::priority_queue<T, less<T>, thin_heap_tag>;
template <class T> using maxBinHeap = __gnu_pbds::priority_queue<T, less<T>, rc_binomial_heap_tag>;
// ordered set and map with policy, policy based data structures
template <class T> using oSet = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T, class U> using oMap = tree<T, U, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// patricia trie, policy based data structure
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> Trie;
// constants
const int INF = (int) 1e9 + 7;
const ll LLINF = (ll) 4e18 + 7;
const double pi = acos(-1.0);
// easy access/use
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define view(x) cout << #x << ": " << x << endl;
#define sz(c) (int)((c).size())
#define all(c) (c).begin(), (c).end()
#define justN(c, n) (c).begin(), (c).begin() + n
#define sq(a) (a) * (a)
#define fi first
#define se second
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define MT make_tuple
#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define FOR(i, start, end) for( int i(start); i < (end); ++ i )
#define REP(i, end) FOR(i, 0, end)
#define FORD(i, start, end) for( int i(start); i >= end; -- i )
#define gcd(a, b) __gcd(a, b)
// bit related builtin functions
#define idxLSB(x) __builtin_ffs(x)
#define idxLSBl(x) __builtin_ffsl(x)
#define idxLSBll(x) __builtin_ffsll(x)
#define leftZeroBits(x) __builtin_clz(x)
#define leftZeroBitsl(x) __builtin_clzl(x)
#define leftZeroBitsll(x) __builtin_clzll(x)
#define rightZeroBits(x) __builtin_ctz(x)
#define rightZeroBitsl(x) __builtin_ctzl(x)
#define rightZeroBitsll(x) __builtin_ctzll(x)
#define cntSetBits(x) __builtin_popcount(x)
#define cntSetBitsl(x) __builtin_popcountl(x)
#define cntSetBitsll(x) __builtin_popcountll(x)

constexpr int MAXN(1000001);
constexpr int MOD(987654321);

bitset<MAXN> sieve; // Check list
vector<int> primes( 100000 );
int idx = 0;

bool isPrime( ll n ){
  if( n < MAXN ) return sieve[n];
  for( int i = 0; i < idx; ++ i ){
    if( n % primes[i] == 0 ) return false;    
  }
  return true;
}

void atkin(){
  if (MAXN > 2)
    primes[idx ++] = 2;
  if (MAXN > 3)
    primes[idx ++] = 3;

  for (ll i = 0; i < MAXN; i++)
    sieve[i] = 0;

  for (ll x = 1; x * x < MAXN; x++) {
    for (ll y = 1; y * y < MAXN; y++) {
      ll n = (4 * x * x) + (y * y);
      if (n <= MAXN && (n % 12 == 1 || n % 12 == 5))
	sieve[n] = sieve[n] ^ 1;
      n = (3 * x * x) + (y * y);
      if (n <= MAXN && n % 12 == 7)
	sieve[n] = sieve[n] ^ 1;
      n = (3 * x * x) - (y * y);
      if (x > y && n <= MAXN && n % 12 == 11)
	sieve[n] = sieve[n] ^ 1;
    }
  }
  for (ll r = 5; r * r < MAXN; r++) {
    if (sieve[r])
      for (ll i = r * r; i < MAXN; i += r * r)
	sieve[i] = 0;
  }

  for (ll a = 5; a < MAXN; a++)
    if (sieve[a])
      primes[idx ++] = a;
  sieve[2] = sieve[3] = 1;
}

ll divs( ll n ){
  ll res = n;
  ll s = 0;
  ll i = 0;
  if( isPrime( n ) ) return 1;
  while( res ){
    if( res % primes[i] == 0 ){
      return res / primes[i];
    }
    else i ++;
  }
  return s;
}

int main(void){
  ll n;
  fastio;
  atkin();
  cin >> n;
  cout << divs( n ) << '\n';
  return 0;
}
