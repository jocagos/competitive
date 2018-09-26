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
// easy access/use
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define view(x) cout << #x << ": " << x << endl;
#define sz(c) (int)((c).size())
#define all(c) (c).begin(), (c).end()
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

int minMoves( const vector<int>& a, int n ){
  int ones = 0;
  REP( i, n ) ones += (a[i] == 1);
  if( ones > 0 ) return n - ones;
  int mi = INF;
  REP( i, n ){
    int d = a[i];
    FOR( j, i + 1, n ){
      d = gcd( d, a[j] );
      if( d == 1 ){
	mi = min( mi, j - i );
	break;
      }
    }
  }
  if( mi == INF ) return -1;
  else return n + mi - 1;
}

int main( void ){
  int n;
  fastio;
  cin >> n;
  vector<int> a( n );
  REP( i, n ) cin >> a[i];
  int ans = minMoves( a, n );
  cout << ans << '\n';
  return 0;
}

// int main(void){
//   int n;
//   fastio;
//   cin >> n;
//   vector<int> a( n );
//   vector<int> b( n );
//   long steps = 0;
//   bool ones = true, zero = false;
//   REP( i, n ){
//     if( zero == true ) cin >> a[i];
//     else cin >> a[i], zero = (a[i] == 0);
//     if( a[i] != 1 ) ones = false;
//   }
//   if( zero ){
//     cout << -1 << '\n';
//     return 0;
//   }
//   bool s = true;
//   if( !ones ){
//     long o = 0;
//     while( !ones ){
//       o = 0;
//       if( s ){
// 	REP( i, n ) b[i] = gcd( a[i], a[(i+1) % n] );
// 	REP( i, n ) if( b[i] == 1 ) ++ o;
// 	if( o == n ) ones = true;
// 	s = !s;
//       }
//       else{
// 	REP( i, n ) a[i] = gcd( b[i], b[(i+1) % n] );
// 	REP( i, n ) if( a[i] == 1 ) ++ o;
// 	if( o == n ) ones = true;
// 	s = !s;
//       }
//       ++ steps;
//     }
//     cout << steps << '\n';
//   }
//   else cout << 0 << '\n';
//   return 0;
// }
