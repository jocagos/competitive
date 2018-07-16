#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<double, double> dd;
typedef pair<int, int> ii;
typedef pair<ii, int> tern;
typedef pair<ii, ii> quad;
typedef vector<int> vi;
typedef vector<ii> vii;
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
const double EPS = 1e-6;

int main(void){
  int n, d, tc = 1;
  vector<dd> intervals(1000);
  while( cin >> n >> d, n | d ){
    double x, y;
    bool able = true;
    for( int i = 0; i < n; ++ i ){
      cin >> x >> y;
      if( y <= d and able ){
	double dist = sqrt( sq(d) - sq(y) );
	intervals[i] = { x - dist, x + dist };
      }
      else able = false;
    }
    cout << "Case " << tc ++ << ": ";
    if( !able ){
      cout << "-1\n";
      continue;
    }
    else{
      int count = 0;
      /* Ok here's a trick: the right lambda/comparator is key.
       * Try with `[]( dd left, dd right ) -> bool { return ( left.fi != right.fi ? left.fi < right.fi : right.se < left.se ); }'
       * instead and the order given (maximum coverage from left to right first)
       * will make the algorithm run into a bug in some test cases
       * thus yielding WA despite the optimizations done
       * I could not find the bug until I saw a solution like mine that differed in cmp.
       */
      sort( intervals.begin(), intervals.begin() + n, []( dd left, dd right ) -> bool { return (left.se == right.se ? left.fi < right.fi : left.se < right.se); } );      
      for( int i = 0; i < n; ){
	int j;
	for( j = 0; j < n; ++ j )
	  if( intervals[j].fi > intervals[i].se ) break;
	i = j;
	count ++;
      }
      cout << count << '\n';
    }
  }
  return 0;
}
