// Place 45 in uHunt!
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long i64;
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
constexpr ii n8[8] = { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } }, n4[4] = { { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 } };
// /* slaps vector */ This bad boy can hold SO MANY
// values to compare a value to!
template<typename T>
bool isIn( T const &value, std::vector<T>& v ){
  return std::find( v.begin(), v.end(), value ) != v.end();
}
// /* slaps initializer_list */ And THIS bad boy can hold
// ANY initializer_list with the same type as the value
// to look forward!
template<typename T>
bool isIn( T const &value, std::initializer_list<T> v ){
  return std::find( v.begin(), v.end(), value ) != v.end();
}

// Took it from CodeForces, great hash for anti-hacking maps and sets
struct myHash {
  static i64 splitmix64( i64 x ) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()( i64 x ) const {
    static const i64 FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

struct PHash {
  size_t operator()( const ii& x ) const {
    return hash<ll>()( ( (ll) x.first ) ^ ( ( (ll) x.second ) << 32 ) );
  }
};

// easy access/use
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define view(x) cout << #x << ": " << x << endl;
#define sz(c) (int)((c).size())
#define all(c) (c).begin(), (c).end()
#define in( a, b, x ) ( (a) <= (x) and (x) <= (b) )
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
constexpr bool V = true, NV = false;
constexpr int MAXN = 105;
constexpr int MAXIC = MAXN * MAXN / 2;
// left: same row / right: diff row
// assign a value given the shape and number of neighbors
const int iso[3][3] = { { 0, 1, 2 }, { 1, 5, 3 }, { 2, 3, 4 } }; // { { { 0, 0 }, 0 }, { { 1, 0 }, 1 }, { { 0, 1 }, 1 }, { { 1, 1 }, 5 }, { { 0, 2 }, 2 }, { { 2, 0 }, 2 }, { { 1, 2 }, 3 }, { { 2, 1 }, 3 }, { { 2, 2 }, 4 } };
int n, m, p;

bool f[MAXN][MAXN], v[MAXN][MAXN];
int g1[MAXIC], g2[MAXIC];

int bfs( int x, int y ){
  int s = 0;
  if( v[x][y] ) return s;
  queue<ii> q;
  q.emplace( x, y );
  while( not q.empty() ){
    ii u = q.front();
    q.pop();
    if( v[u.fi][u.se] ) continue;
    v[u.fi][u.se] = V;
    ii t = { 0, 0 };
    if( u.fi > 0 ){
      if( f[u.fi - 1][u.se] ){
	t.fi ++;
	if( not v[u.fi - 1][u.se] ) q.emplace( u.fi - 1, u.se );
      }
    }
    if( u.fi + 1 < n ){
      if( f[u.fi + 1][u.se] ){
	t.fi ++;
	if( not v[u.fi + 1][u.se] ) q.emplace( u.fi + 1, u.se );
      }
    }
    if( u.se > 0 ){
      if( f[u.fi][u.se - 1] ){
	t.se ++;
	if( not v[u.fi][u.se - 1] ) q.emplace( u.fi, u.se - 1 );
      }
    }
    if( u.se + 1 < m ){
      if( f[u.fi][u.se + 1] ){
	t.se ++;
	if( not v[u.fi][u.se + 1] ) q.emplace( u.fi, u.se + 1 );
      }
    }
    s += iso[t.fi][t.se];
  }
  return s;
}

int main(void){
  int tc;
  fastio;
  cin >> tc;
  while( tc -- ){
    cin >> n >> m >> p;
    int x, y, idx = 0, maxIdx = 0;
    REP( i, p ){
      cin >> x >> y;
      f[x][y] = V;
    }
    REP( i, n ){
      REP( j, m ){
	if( f[i][j] and not v[i][j] ){
	  g1[idx++] = bfs( i, j );
	}
      }
    }
    memset( f, 0, sizeof f );
    memset( v, 0, sizeof v );
    maxIdx = idx;
    idx = 0;
    REP( i, p ){
      cin >> x >> y;
      f[x][y] = V;
    }
    REP( i, n ){
      REP( j, m ){
	if( f[i][j] and not v[i][j] ){
	  g2[idx++] = bfs( i, j );
	}
      }
    }
    bool ans = true;
    sort( g1, g1 + maxIdx );
    sort( g2, g2 + maxIdx );
    for( int i = 0; ans and i < maxIdx; ++ i ){
      if( g1[i] != g2[i] ) ans = false;
    }
    if( ans ) cout << "YES\n";
    else cout << "NO\n";
    memset( f, 0, sizeof f );
    memset( v, 0, sizeof v );
    memset( g1, 0, sizeof g1 );
    memset( g2, 0, sizeof g2 );
  }
  return 0;
}
