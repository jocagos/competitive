#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
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
#define fastio ios::sync_with_stdio(0); cin.tie(0)
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

#define EPS 1.0e-7L

int p, q, r, s, t, u;

inline double f( double x ){
  return p * exp( -x ) + q * sin( x ) + r * cos( x ) + s * tan( x ) + t * x * x + u;
}

inline double fp( double x ){
  return -p * exp( -x ) + q * cos( x ) - r * sin( x ) + s / ( cos( x ) * cos( x ) ) + 2 * t * x;
}


inline double newton(){
  if( f(0) == 0 ) return 0;
  double x1 = 0.5;
  for( double x = 0.5; ; x = x1 ){
    x1 = x - f(x) / fp(x);
    if( fabs( x1 - x ) < EPS ) return x1;
  }
}

int main(void){
  fastio;
  while( cin >> p ){
    cin >> q >> r >> s >> t >> u;
    bool sol = false, flesser = ( f( 0.0 ) < 0 ? true : false ), sgreater = ( f( 1.0 ) > 0 ? true : false );
    if( (flesser and sgreater) or (!flesser and !sgreater) ) sol = true;
    else sol = false;
    if( sol ){
      double ans = newton();
      // double x0 = 0.5L, xn = x0, eval = f( x0 );
      // REP( i, 10 ){
      // 	if( fabs(eval) < EPS ) break;
      // 	xn = xn - f( xn ) / fp( xn );
      // 	eval = f( xn);
      // }
      cout << setprecision(4) << fixed << ans << endl;
    }
    else cout << "No solution\n";
  }
  return 0;
}
