// 0.930s, rank 979
// too much cases!
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using i64 = unsigned long long;
using ld = long double;
// using ii = tuple<int, int>; // or pair<int, int>
// using dd = tuple<double, double>; // or pair< double, double >
template <class T> using twin = tuple<T, T>;
template <class T> using triad = tuple<T, T, T>;
template <class T> using quad = tuple<T, T, T, T>;
template <class T, class U = T, class V = T>
using mtriad = tuple<T, U, V>;

template <class T, class U = T, class V = T, class W = T>
using mquad = tuple<T, U, V, W>;

using vi = vector<int>;
using vs = vector<string>;
using vd = vector<double>;
using vld = vector<ld>;
template <class T, class U = T>
using vtwin = vector<tuple<T, U>>;
template <class T, class U = T, class V = T>
using vtriad = vector<tuple<T, U, V>>;
template <class T, class U = T, class V = T, class W = T>
using vquad = vector<tuple<T, U, V, W>>;

// minHeap, BinomialHeap and FibonacciHeap for later use, policy based data structures
/* NOTES:
`pairing_heap_tag` is good for non-primitive data types like `string`
`binary_heap_tag` is good for primitive data types
`binomial_heap_tag` is good for responsiveness
`rc_binomial_heap_tag` has more responsiveness at the cost of worse constants
`thin_heap_tag` is good for graph algorithms (FibonacciHeap)
 */
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
constexpr twin<int> n8[8] = { { -1, -1 }, // upper left
			      { -1, 0 }, // upper middle
			      { -1, 1 }, // upper right
			      { 0, -1 }, // center left
			      { 0, 1 }, // center right
			      { 1, -1 }, // lower left
			      { 1, 0 }, // lower middle
			      { 1, 1 } // lower right
                     },
                     n4[4] = { { -1, 0 }, // down
			       { 0, -1 }, // left
			       { 0, 1 }, // right
			       { 1, 0 } // up
		     };
constexpr triad<int> n3d[] = { { 0, -1, 0 }, // up
		     { 0, 1, 0 }, // down
		     { -1, 0, 0 }, // left
		     { 1, 0, 0 }, // right
		     { 0, 0, -1 }, // backward
		     { 0, 0, 1 } // forward
};
constexpr bool V = true, NV = false;
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

/*
 * Only valid if T, U, V are trivially compared with operator< or operator<=
 */

template <typename T, typename U, typename V>
inline bool in( T a, U b, V x ){
  return (a <= x) and (x <= b);
}

template <typename T, typename U, typename V>
inline bool inx( T a, U b, V x ){
  return (a <= x) and (x < b);
}

template <typename T, typename U, typename V>
inline bool xin( T a, U b, V x ){
  return (a < x) and (x <= b);
}

template <typename T, typename U, typename V>
inline bool xinx( T a, U b, V x ){
  return (a < x) and (x < b);
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

/* FAST I/O for integers
 * USE: just add the characters to `buf` and check if you are close to overflow
 * and if so just print `buf` then reset iterator to buf.
char buf[10000000];
constexpr int ZERO = 0, NEWLINE = 1, WHITESPACE = 2;

// let's try it again lmao
int next_int( void ){
  char c;
  do{ c = getchar_unlocked(); } while( c != '-' and !isdigit( c ) );
  bool neg = (c == '-');
  int r = neg ? 0 : c - '0';
  while( isdigit( c = getchar_unlocked() ) ) r = 10 * r + (c - '0');
  return neg ? -r : r;
}

int print_int( int N, int idx, int nd = ZERO ){
  if( N < 10 ) buf[idx ++] = N + '0';
  else{
    buf[idx ++] = (N / 10) + '0';
    buf[idx ++] = N % 10 + '0';
  }
  if( nd == WHITESPACE ) buf[idx ++] = ' ';
  else if( nd == NEWLINE ) buf[idx ++] = '\n';
  else buf[idx ++] = '\0';
  return idx;
}
 */

// can't remove these macros
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define viewStr(s) cout << #s << ": >" << (s) << "<" << endl
#define view(x) cout << #x << ": " << x << endl
#define sz(c) (int)((c).size())
#define all(c) (c).begin(), (c).end()
// pretty useful though hard to make a template out of it that works
// with almost any type without casts and so
// it might work:
/*
  template <typename T, typename U, typename V>
  inline bool in( T a, U b, V x ){
    return a <= x and x <= b;
  }
 */
// easy access/use
// #define in( a, b, x ) ( (a) <= (x) and (x) <= (b) )
#define justN(c, n) (c).begin(), (c).begin() + n
#define sq(a) (a) * (a)
#define fi first
#define se second
#define g0 get<0>
#define g1 get<1>
#define g2 get<2>
#define g3 get<3>
#define g4 get<4>
#define g5 get<5>
#define g6 get<6>
#define g7 get<7>
#define g8 get<8>
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
constexpr int MAXN = 1010;
constexpr int sx = 0, sy = 0;
int dx, dy, n, m, tc;
int grid[MAXN][MAXN];

int main(void){
  fastio;
  cin >> tc;
  while( tc -- ){
    cin >> n >> m;
    dx = n - 1;
    dy = m - 1;
    REP( i, n ){
      REP( j, m ){
	cin >> grid[i][j];
      }
    }
    vector<vi> dist( MAXN, vi( MAXN, INF ) );
    dist[sx][sy] = grid[sx][sy];
    auto start = chrono::steady_clock::now();
#ifdef FPQ
    // dijkstra with pairing heap
    string __case("GNU PBDS' Pairing Heap PQ");
    minBinHeap<triad<int>> pq;
#elif defined(FIBOPQ)
    // dijsktra with fibo heap
    string __case("GNU PBDS' Fibonacci Heap PQ");
    minFHeap<triad<int>> pq;
#else
    // dijkstra with `priority_queue`
    string __case("C++ Priority Queue");
    std::priority_queue< triad<int>, vector<triad<int>>, greater<triad<int>> > pq;
#endif
    triad<int> tmp { dist[sx][sy], sx, sy };
    pq.push( tmp );
    while( not pq.empty() ){
      tmp = pq.top();
      pq.pop();
      int d, x, y;
      tie( d, x, y ) = tmp;
      if( d > dist[x][y] ) continue; // skip if distance is greater
      for( auto p : n4 ){
	int diff_x, diff_y;
	tie( diff_x, diff_y ) = p;
	if( in( 0, n - 1, x + diff_x ) and in( 0, m - 1, y + diff_y ) and dist[x][y] + grid[x + diff_x][y + diff_y] < dist[x + diff_x][y + diff_y] ){
// #ifdef DBG
// 	  cerr << "Coords (" << setw( 3 ) << x + diff_x << ", " << setw( 3 ) << y + diff_y << ") spawned correctly" << endl;
// #endif
	  dist[x + diff_x][y + diff_y] = dist[x][y] + grid[x + diff_x][y + diff_y];
	  tmp = { dist[x + diff_x][y + diff_y], x + diff_x, y + diff_y };
	  pq.push( tmp );
	}
      }
    }
    auto end = chrono::steady_clock::now();
    cerr << "Time taken with " << __case << " was " << chrono::duration_cast<chrono::nanoseconds>( end - start ).count() << " ns." << endl;
    // check dist matrix
#ifdef DBG
    cerr << "\t====DIST MATRIX:====" << endl;
    cerr << "=========================================" << endl;
    REP( i, n ){
      REP( j, m ){
	cerr << setw( 3 ) << (dist[i][j] != INF ? dist[i][j] : -1) << " ";
      }
      cerr << endl;
    }
    cerr << "\t====END OF DIST MATRIX====" << endl << endl;
#endif
    cout << dist[dx][dy] << '\n';
  }
  return 0;
}
