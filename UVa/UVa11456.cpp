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

// This version should be faster as we access directly the vectors
template <typename RAI, typename Compare>
ll LIDS( RAI beginning, RAI ending, Compare comp ){
  auto s = distance( beginning, ending );
  vector<ll> L( s );
  auto source = beginning;
  ll lisCount = 0, length = 0;
  REP( i, s ){
    size_t pos = lower_bound( L.begin(), L.begin() + lisCount, source[i], comp ) - L.begin(); // can't go negative
    L[pos] = source[i];
    length = pos + 1;
    if( pos == lisCount ) lisCount ++;
  }
  return length;
}

int main(void){
  int tc, n;
  vector<ll> a( 2001, 0 );
  fastio;
  cin >> tc;
  while( tc -- ){ // let tc = k
    cin >> n;
    FOR( i, 0, n ) cin >> a[i];
    // LIS
    ll longestTrain = 0;
    // You need not to store them so you can just do this
    // Complexity:
    FOR( i, 0, n ){ // O(n) times
      ll lis = LIDS( reverse_iterator<vector<ll>::iterator>( a.begin() + n ),
		     reverse_iterator<vector<ll>::iterator>( a.begin() + i ),
		     less<ll>() ); // O(n lgn)
      ll lds = LIDS( reverse_iterator<vector<ll>::iterator>( a.begin() + n ),
		     reverse_iterator<vector<ll>::iterator>( a.begin() + i ),
		     greater<ll>() ); // O(n lgn)
      longestTrain = max( longestTrain, lis + lds - 1 ); // O(1)
    }
    // Thus, O(k) times O(n) times O(n lgn) + O(1) => O(k * n^2 * lgn)
    cout << longestTrain << '\n';
  }
  return 0;
}
