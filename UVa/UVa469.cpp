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
constexpr ii n8[8] = { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } }, n4[4] = { { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 } };
constexpr int MAXN = 110;
constexpr bool V = true, NV = false;
char g[MAXN][MAXN];
int dp[MAXN][MAXN];
bool v[MAXN][MAXN];
bool pushed[MAXN][MAXN];
int n, m;

pair<int, ii> bfs( int x, int y ){
  if( g[x][y] == 'L' or v[x][y] ) return { dp[x][y], { x, y } };
  queue<ii> q;
  q.emplace( x, y );
  int c = 0;
  ii p;
  while( not q.empty() ){
    p = q.front(); q.pop();
    if( !v[p.fi][p.se] ) v[p.fi][p.se] = V, c ++;
    // add neighbours
    REP( i, 8 ){
      // if( p.fi == 2 and p.se == 1 ){
      // 	cout << "xin( 0, " << n - 1 << ", " << p.fi + n8[i].fi << ") = " << in( 0, n - 1, p.fi + n8[i].fi ) << endl;
      // 	cout << "yin( 0, " << m - 1 << ", " << p.se + n8[i].se << ") = " << in( 0, m - 1, p.se + n8[i].se ) << endl;
      // }
      if( in( 0, n - 1, p.fi + n8[i].fi ) and in( 0, m - 1, p.se + n8[i].se ) ) if( g[p.fi + n8[i].fi][p.se + n8[i].se] == 'W' and !v[p.fi + n8[i].fi][p.se + n8[i].se] and !pushed[p.fi + n8[i].fi][p.se + n8[i].se] ){
	  q.push( {p.fi + n8[i].fi, p.se + n8[i].se} );
	  pushed[p.fi + n8[i].fi][p.se + n8[i].se] = V;
	  // cout << "(" << p.fi << ", " << p.se << ") pushed (" << p.fi + n8[i].fi << ", " << p.se + n8[i].se << ")" << endl;
	}
    }
  }
  pair<int, ii> ans;
  ans.fi = c;
  ans.se = p;
  return ans;
}

void dps( int x, int y, int val ){
  if( g[x][y] == '.' or g[x][y] == 'L' ) return;
  dp[x][y] = val;
  g[x][y] = '.';
  REP( i, 8 ){
    if( in( 0, n - 1, x + n8[i].fi ) and in( 0, m - 1, y + n8[i].se ) ) if( g[x + n8[i].fi][y + n8[i].se] == 'W' and v[x + n8[i].fi][y + n8[i].se] ) dps( x + n8[i].fi, y + n8[i].se, val );
  }
}

int main(void){
  int tc;
  string line;
  fastio;
  cin >> tc;
  getline( cin, line );
  getline( cin, line );
  while( tc -- ){
    auto start = chrono::high_resolution_clock::now();
    int idx = 0;
    while( getline( cin, line ), line[0] == 'W' or line[0] == 'L' ){
      m = line.length();
      REP( i, (int)line.length() ) g[idx][i] = line[i];
      ++ idx;
    }
    n = idx;
    // view(n);
    // view(m);
    pair<int, ii> d;
    REP( i, n ){
      REP( j, m ){
	if( !v[i][j] ){
	  d = bfs( i, j );
	  dps( d.se.fi, d.se.se, d.fi );
	}
      }
    }
    // REP( i, n ){
    //   REP( j, m ){
    // 	cout << g[i][j];
    //   }
    //   cout << endl;
    // }
    // REP( i, n ){
    //   REP( j, m ){
    // 	cout << setw(3) << dp[i][j];
    //   }
    //   cout << endl;
    // }
    istringstream iss( line );
    int a, b;
    iss >> a >> b;
    cout  << dp[a-1][b-1] << '\n';
    while( line != "" ){
      getline( cin, line );
      if( line == "" ) break;
      istringstream iss2( line );
      iss2 >> a >> b;
      cout  << dp[a-1][b-1] << '\n';
    }
    memset( g, 0, sizeof g ); memset( dp, 0, sizeof dp ); memset( v, 0, sizeof v ); memset( pushed, 0, sizeof pushed );
    if( tc ) cout << '\n';
    auto end = chrono::high_resolution_clock::now();
    cerr << "tc : " << tc << " took " << chrono::duration_cast<chrono::nanoseconds>( end - start ).count() << " nanoseconds\n";
  }
  return 0;
}
