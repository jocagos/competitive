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
constexpr int MAXW = 410, MAXH = 210;
constexpr bool V = true, NV = false;
constexpr char BLACK = '1', WHITE = '0';
unordered_map<char, int> x2d { { '0', 0 }, { '1', 1 }, { '2', 2 }, { '3', 3 }, { '4', 4 }, { '5', 5 }, { '6', 6 }, { '7', 7 }, { '8', 8 }, { '9', 9 }, { 'a', 10 }, { 'b', 11 }, { 'c', 12 }, { 'd', 13 }, { 'e', 14 }, { 'f', 15 } };
unordered_map<char, string> x2s { { '0', "0000" }, { '1', "0001" }, { '2', "0010" }, { '3', "0011" }, { '4', "0100" }, { '5', "0101" }, { '6', "0110" }, { '7', "01110" }, { '8', "1000" }, { '9', "1001" }, { 'a', "1010" }, { 'b', "1011" }, { 'c', "1100" }, { 'd', "1101" }, { 'e', "1110" }, { 'f', "1111" } };
unordered_map<int, char> c2h { { 1, 'A' }, { 3, 'J' }, { 5, 'D' }, { 4, 'S' }, { 0, 'W' }, { 2, 'K' } };
int m, n;
char g[MAXH][MAXW];
bool v[MAXH][MAXW];
set<ii> used;

void dfsBack( int x, int y ){
  if( v[x][y] or g[x][y] == BLACK ) return;
  v[x][y] = V;
  used.emplace( x, y );
  for( auto p : n4 ){
    if( in( 0, n - 1, x + p.fi ) and in( 0, 4 * m - 1, y + p.se ) ){
      if( g[x + p.fi][y + p.se] == WHITE ) dfsBack( x + p.fi, y + p.se );
    }
  }
}

int bfs( int x, int y ){ // bfs 0-1, flood fill white cells first then black ones
  int c = 0;
  if( v[x][y] ) return c;
  char color = g[x][y];
  deque<ii> d;
  d.emplace_back( x, y );
  while( not d.empty() ){
    ii p = d.front();
    used.emplace( x, y );
    d.pop_front();
    v[p.fi][p.se] = V;
    for( auto q : n4 ){
      if( in( 0, n - 1, p.fi + q.fi ) and in( 0, 4 * m - 1, p.se + q.se ) ){
	if( not v[p.fi + q.fi][p.se + q.se] and used.find( { p.fi + q.fi, p.se + q.se } ) == used.end() ){
	  if( g[p.fi + q.fi][p.se + q.se] == WHITE ) d.emplace_front( p.fi + q.fi, p.se + q.se );
	  else d.emplace_back( p.fi + q.fi, p.se + q.se );
	  used.emplace( p.fi + q.fi, p.se + q.se );
	}
      }
    }
    if( color == BLACK and g[p.fi][p.se] == WHITE ){
      color = WHITE;
      ++ c;
    }
    else if( color == WHITE and g[p.fi][p.se] == BLACK ){
      color = BLACK;
    }
  }
  return c;
}

// int dfsBlack( int x, int y, int color = BLACK, int c = 0 ){
//   if( v[x][y] ) return c;
//   int ans = c;
//   if( color == BLACK and g[x][y] == WHITE ) ans ++, color = WHITE;
//   if( color == WHITE and g[x][y] == BLACK ) color = BLACK;
//   v[x][y] = V;
//   deque<ii> d;
//   for( auto p : n4 ){
//     if( in( 0, n - 1, x + p.fi ) and in( 0, m * 4 - 1, y + p.se ) )
//       if( not v[x + p.fi][y + p.se] ){
// 	if( g[x + p.fi][y + p.se] == WHITE ) d.emplace_front( { x + p.fi, y + p.se } );
// 	else d.emplace_back( { x + p.fi, y + p.se } );	
//       }
//   }
//   while( not d.empty() ){
//     ii p = d.front(); d.pop_front();
//     ans = max( ans, dfsBlack( x + p.fi, y + p.se, color, ans ) );
//   }
//   return ans;
// }

int main(void){
  fastio;
  int tc = 1;
  while( cin >> n >> m, n | m ){
    if( n == 0 and m == 0 ) break;
    // print which case we are in
    // cout << "Case with n = " << n << " and m = " << m << endl;
    char c;
    string ans = "";
    // int cc = 1; // background counts too!
    REP( i, n ){
      for( int j = 0; j < m * 4; j += 4 ){
	cin >> c;
	REP( k, 4 ) g[i][j + k] = x2s[c][k];
      }
    }
    // Print matrix of chars
    // REP( i, n ){
    //   for( int j = 0; j < m * 4; j ++ ) cout << g[i][j];
    //   cout << endl;
    // }
    // Separate matrices
    // cout << "---------------------" << endl;
    // Flood fill border
    // auto start = chrono::system_clock::now();
    for( int i = 0; i < n; ++ i ){
      dfsBack( i, 0 );
      dfsBack( i, n - 1 );
    }
    for( int j = 1; j < 4 * m; ++ j ){
      dfsBack( 0, j );
      dfsBack( n - 1, j );
    }
    // auto end = chrono::system_clock::now();
    // auto t1n = chrono::duration_cast<chrono::nanoseconds>( end - start ).count();
    // auto t1m = chrono::duration_cast<chrono::milliseconds>( end - start ).count();
    // dfsBack( 0, 0 );
    // Print matrix of visited values with Y as 1 and N as 0
    // REP( i, n ){
    //   for( int j = 0; j < m * 4; j ++ ) cout << ( v[i][j] ? 'Y' : 'N' );
    //   cout << endl;
    // }
    // start = chrono::system_clock::now();
    REP( i, n ){
      for( int j = 0; j < m * 4; j ++ ){
	if( not v[i][j] and g[i][j] == BLACK ){
	  int qcc = bfs( i, j );
	  // PRint how many connected components we found inside a black structure and where
	  // cout << "got " << qcc << " cc from (" << i << ", " << j << ")" << endl;
	  ans += c2h[qcc];
	}
      }
    }
    sort( all( ans ) );
    // end = chrono::system_clock::now();
    // auto t2n = chrono::duration_cast<chrono::nanoseconds>( end - start ).count();
    // auto t2m = chrono::duration_cast<chrono::milliseconds>( end - start ).count();
    cout << "Case " << tc ++ << ": " << ans << '\n';
    // cerr << "Background time was " << t1n << " nanoseconds, or " << t1m << " milliseconds." << endl;
    // cerr << "Queries time was " << t2n << " nanoseconds, or " << t2m << " milliseconds." << endl;
    memset( g, 0, sizeof g );
    memset( v, 0, sizeof v );
    used.clear();
  }
  return 0;
}
