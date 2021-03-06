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
constexpr int MAXN = 110, MAXM =  10100;
class UFDS {
private:
  vector<int> p, rank, set_size;
  long long num_sets, offset;
public:
  UFDS( int N ){
    set_size.assign(N, 1);
    num_sets = N;
    rank.assign(N, 0);
    p.assign(N, 0);
    offset = 0;
    for (int i = 0; i < N; i++) p[i] = i;
  }

  UFDS( int N, int max_size ){ // to reuse it
    set_size.assign( max_size, 1 );
    num_sets = N;
    rank.assign( max_size, 0 );
    p.assign( max_size, 0 );
    offset = 0;
    for(int i = 0; i < N; i++) p[i] = i;
  }
  
  UFDS( int N, int max_size, int idx ){ // when you need offsets, or 1-based idx
    set_size.assign( max_size, 1 );
    num_sets = N, offset = idx;
    rank.assign( max_size, 0 );
    p.assign( max_size, 0 );
    for( int i = idx; i < N + idx; ++ i ) p[i] = i;
  }

  void init( int N, int idx = 0 ){
    offset = idx;
    for( int i = offset; i < N + offset; ++ i ){
      rank[i] = set_size[i] = 1;
      p[i] = i;
    }
  }
  
  int find_set(int i) { return (p[i] == i) ? i : (p[i] = find_set(p[i])); }
  bool is_same_set(int i, int j) { return find_set(i) == find_set(j); }
  bool union_set(int i, int j) { 
    if (!is_same_set(i, j)) {
      num_sets--; 
      int x = find_set(i), y = find_set(j);
      if (rank[x] > rank[y]) {
	p[y] = x;
	set_size[x] += set_size[y];
      }
      else{
	p[x] = y;
	set_size[y] += set_size[x];
	if (rank[x] == rank[y]) rank[y]++;
      }
      return true;
    }
    return false;
  }
  int how_many() { return num_sets; }
  int size_of_set(int i) { return set_size[find_set(i)]; }
};

int tc, m, n, edx, u, v, w;
vtriad<int> edges( MAXM );
UFDS ufds( MAXN, MAXN );

int main(void){
  fastio;
  cin >> tc;
  FOR( _, 1, tc + 1 ){
    cin >> n >> m;
    ufds.init( n );
    REP( i, m ){
      cin >> u >> v >> w;
      edges[i] = { w, u, v };
    }
    sort( justN( edges, m ), greater<triad<int>>() );
    // REP( i, m ){
    //   tie( w, u ,v ) = edges[i];
    //   cout << "(" << w << ", " << u << ", " << v << ")\n";
    // }
    int it = 0;
    REP( i, m ){
      if( ufds.how_many() == 1 ) break;
      tie( w, u, v ) = edges[i];
      if( ufds.union_set( u, v ) ) it = i;
    }
    cout << "Case #" << _ << ": " << get<0>( edges[it] ) << '\n';
  }
  return 0;
}
