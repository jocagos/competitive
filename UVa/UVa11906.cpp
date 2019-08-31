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
//typedef vector<vector<int>> grid;
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
#define in( a, b, x ) ( (a) <= (x) and (x) < (b) )
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
#define WATER -2

int grid[100][100], even, odd, n, tc, r, c, m, w;
vector<ii> moves { { 1, 1 }, { 1, -1 }, { -1, 1 }, { -1, -1 } };

void dfs( int x, int y ){
  grid[x][y] = 1;
  unordered_map<int, bool> used;
  REP( _, (int) moves.size() ){
    int f = x + moves[_].fi * m, s = y + moves[_].se * n;
    if( in( 0, r, f ) and in( 0, c, s ) and grid[f][s] != WATER and !used[f * 100 + s] ){
      grid[x][y] ++;
      used[f * 100 + s] = true;
      if( grid[f][s] == 0 ) dfs( f, s );
    }
    f = x + moves[_].fi * n, s = y + moves[_].se * m;
    if( in( 0, r, f ) and in( 0, c, s ) and grid[f][s] != WATER and !used[f * 100 + s] ){
      grid[x][y] ++;
      used[f * 100 + s] = true;
      if( grid[f][s] == 0 ) dfs( f, s );
    }
  }
  if( grid[x][y] > 0 ){
    if( grid[x][y] % 2 ) ++ odd;
    else if( grid[x][y] % 2 == 0 ) ++ even;
  }
}

int main(void){
  n = tc = r = c = m = w = 0;
  fastio;
  cin >> tc;
  FOR( _, 1, tc + 1 ){
    cin >> r >> c >> m >> n >> w;
    memset( grid, 0, sizeof grid );
    REP( i, w ){
      int x, y;
      cin >> x >> y;
      grid[x][y] = WATER;
    }
    even = 0, odd = 0;
    if( grid[0][0] == 0 ) dfs( 0, 0 );
    cout << "Case " << _ << ": " << odd << " " << even << '\n';
  }
  return 0;
}
