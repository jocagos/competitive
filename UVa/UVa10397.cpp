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
constexpr twin<int> n8[8] = { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } }, n4[4] = { { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 } };
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
constexpr int MAXSIZE = 1000001;
constexpr int MAXN = 770, MAXM = 770 * 770, MAXE = 1100;
int pa[MAXSIZE], ra[MAXSIZE], set_size[MAXSIZE];
int num_sets = MAXSIZE;
int n, m, edx, u, v;
double w, mst;
vtwin<int> points( MAXN ), existing( MAXE );
vtriad<double, int, int> edges( MAXM );

void init( int n, int idx = 0 ){
  num_sets = n + idx;
  for( int i = 0; i < num_sets; ++ i ){
    pa[i] = i;
    ra[i] = set_size[i] = 1;
  }
}

int find_set( int i ){ return pa[i] == i ? i : pa[i] = find_set( pa[i] ); }
bool is_same_set( int i, int j ){ return find_set( i ) == find_set( j ); }
bool union_set( int i, int j ){
  if( not is_same_set( i, j ) ){
    num_sets --;
    int x = find_set( i ), y = find_set( j );
    if( ra[x] > ra[y] ){
      pa[y] = x;
      set_size[x] += set_size[y];
    }
    else{
      pa[x] = y;
      set_size[y] += set_size[x];
      if( ra[x] == ra[y] ) ra[y] ++;
    }
    return true;
  }
  return false;
}

int size_of_set( int i ){ return set_size[find_set( i )]; }

int main(void){
  fastio;
  while( cin >> n ){
    edx = mst = 0;
    REP( i, n ){
      cin >> u >> v;
      points[i + 1] = { u, v };
    }
    cin >> m;
    init( n, 1 );
    REP( i, m ){
      cin >> u >> v;
      existing[i] = { u, v };
      union_set( u, v );
    }
    int x1, x2, y1, y2;
    FOR( i, 1, n + 1 ){
      tie( x1, y1 ) = points[i];
      FOR( j, i + 1, n + 1 ){
	tie( x2, y2 ) = points[j];
	edges[edx ++] = { hypot( x1 - x2, y1 - y2 ), i, j };
      }
    }
    sort( justN( edges, edx ) );
    REP( i, edx ){
      if( num_sets == 1 ) break;
      tie( w, u, v ) = edges[i];
      if( union_set( u, v ) ) mst += w;
    }
    cout << setprecision(2) << fixed << mst << '\n';
  }
  return 0;
}
