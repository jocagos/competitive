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
typedef vector<string> vs;
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

// easy access/use
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define prepare( cont, n ) (cont).clear(); (cont).resize( n )
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
constexpr int MAXN = 210;
constexpr int BLACK = 1, WHITE = 0, NC = -1;
int n, m;
vi color( MAXN, NC );
bool ans = true, v[MAXN];
vector<vi> g;

// bicoloring with dfs, basically you start at 0, color it if it lacks a colour
// then you send 1 - c as color (which is WHITE or BLACK always) BUT
// if we find a connected component has the same colour as u
// we mark ans as false and return in the next iteration
void dfs( int u = 0, int c = BLACK ){ // default parameters, start at 0 and colour BLACK the first point
  v[u] = V; // mark as visited
  if( color[u] == NC ) color[u] = c; // color the node
  for( auto p : g[u] ){
    if( not ans ) return; // break in case it is not bipartite
    if( not v[p] and color[p] == NC ) dfs( p, 1 - color[u] ); // color recursively
    else if( color[p] == color[u] ) ans = false; // to break early
  }
}

// with BFS it would be:
void bfs( int u = 0 ){
  queue<int> q;
  q.push( u );
  color[u] = BLACK; // or WHITE, it doesn't matter
  while( not q.empty() and ans ){ // to break early
    int p = q.front(); q.pop();
    for( auto r : g[p] ){
      if( color[r] == NC ){ // if not colored
	color[r] = 1 - color[p]; // color it
	q.push( r ); // and enqueue it
      }
      else if( color[r] == color[p] ) ans = false; // we don't need to break immediately
    }
  }
}

int main(void){
  fastio;
  while( cin >> n, n ){
    memset( v, false, sizeof v );
    ans = true;
    fill( all( color ), NC );
    prepare( g, n );
    cin >> m;
    REP( i, m ){
      int x, y;
      cin >> x >> y;
      g[x].EB( y );
      g[y].EB( x );
    }
    dfs(); // we would switch to bfs() here
    if( ans ) cout << "BICOLORABLE.\n";
    else cout << "NOT BICOLORABLE.\n";
    // to check graph by color, node, and connections
    // REP( i, n ){
    //   cout << "Node (" << i << ", " << (color[i] ? "B" : "W") << "): {";
    //   REP( j, (int)g[i].size() ) cout << " (" << g[i][j] << ", " << (color[g[i][j]] ? "B" : "W") << ")";
    //   cout << "}\n";
    // }
  }
  return 0;
}
