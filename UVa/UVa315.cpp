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
#define view(x) cout << #x << ": " << x << endl
#define viewStr(s) cout << #s << ": >" << (s) << "<" << endl
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
constexpr int MAXN = 110, UNV = 0;
int n;
int dfsRoot, rootChildren, dfsCount = 1;
vi dfsNum( MAXN, 0 ), dfsLow( MAXN, 0 ), dfsParent( MAXN, 0 );
bitset<MAXN> artVertex( 0 );
vector<vi> g;

void articulations( int u ){ // find articulations with dfs
  dfsLow[u] = dfsNum[u] = dfsCount++; // reset values to the first value of dfsCount then add 1 to dfsCount for next iteration
  for( auto v : g[u] ){ // for every neighbor
    if( dfsNum[v] == UNV ){ // if it has not been visited
      dfsParent[v] = u; // visit it and mark its parent
      if( u == dfsRoot ) ++ rootChildren; // then if it is the root, add it to children count
      articulations( v ); // recursively add more nodes
      if( u != dfsRoot and dfsLow[v] >= dfsNum[u] ) artVertex[u] = true; // now if it is not the root and the low value of v is equal or greater than that of u we mark it as articulation vertex
      dfsLow[u] = min( dfsLow[u], dfsLow[v] ); // then we assign to low of u the value of either u or v, whichever is lesser to mark it as a cycle
    }
    else if( v != dfsParent[u] ) dfsLow[u] = min( dfsLow[u], dfsNum[v] ); // otherwise we just get the value in case it is a cycle
  }
}

int main(void){
  fastio;
  while( cin >> n, n ){
    g.assign( n + 1, vi() );
    dfsNum.assign( n + 1, UNV );
    dfsParent.assign( n + 1, UNV );
    dfsLow.assign( n + 1, UNV );
    artVertex.reset();
    dfsCount = 1;
    // dfsCount = dfsRoot = rootChildren = 0;
    string line;
    while( getline( cin, line ), line != "0" ){
      if( line == "" ) continue;
      istringstream iss( line );
      // viewStr(line);
      int u, v;
      iss >> u;
      // if( m == 0 ) continue;
      while( iss >> v ){
	g[u].EB( v );
	g[v].EB( u );
      }
    }
    FOR( i, 1, n + 1 ){
      if( dfsNum[i] == UNV ){
	dfsRoot = i;
	rootChildren = 0;
	articulations(i);
	artVertex[i] = (rootChildren > 1);
      }
    }
    cout << artVertex.count() << '\n';
  }
  return 0;
}
