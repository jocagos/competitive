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
#define ii pair<int, int>
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

int main(void){
  fastio;
  int c, s, t = 1;
  vector<int> specimens(10, 0), sums(5, 0);
  vector<vector<ii>> sorted(5);
  vector<ii> specs_idx(10);
  vector<vector<int>> chambers;
  while( cin >> c >> s ){
    sorted.clear();
    specs_idx.clear();
    specimens.clear();
    chambers.clear();
    sums.clear();
    specs_idx.resize(s);
    sorted.resize(c);
    sums.resize(c);
    specimens.resize(s);
    chambers.resize(c);
    double avg = 0.0L, imbalance = 0.0L;
    for( int i = 0; i < s; ++ i ){
      cin >> specimens[i];
      specs_idx[i] = {specimens[i], i+1};
      avg += specimens[i];
    }
    avg /= c;
    while( sz(specimens) < 2 * c ) specimens.EB(0), specs_idx.EB(0, s+1);
    sort( all( specimens ) );
    auto sIdxSort = [s]( ii left, ii right ) -> bool {
      return left.fi < right.fi;
    };
    sort( all( specs_idx ), sIdxSort );
    auto sorter = [s](vector<ii> left, vector<ii> right) -> bool {
      int ml = ( sz(left) == 2 ? min(left[0].se, left[1].se) : ( sz(left) ? left[0].se : s+1 ) );
      int mr = ( sz(right) == 2 ? min(right[0].se, right[1].se) : ( sz(right) ? right[0].se : s+1 ) );
      return ml < mr;
    };
    for( int i = 0; i < sz(sums); ++ i ){
      sums[i] = specimens[i] + specimens[sz(specimens)-i-1];
      if( specimens[i] ) chambers[i].EB(specimens[i]), sorted[i].PB(specs_idx[i]) ;
      if( specimens[sz(specimens)-i-1] ) chambers[i].EB(specimens[sz(specimens)-i-1]), sorted[i].PB( specs_idx[sz(specimens)-i-1] );
      imbalance += abs( sums[i] - avg );
    }
    sort( all( sorted ), sorter );
    cout << "Set #" << t++;
    int chamber = 0;
    for( auto& v : sorted ) sort( all(v), []( ii left, ii right ) -> bool { return left.se < right.se; } );
    for( auto v : sorted ){
      cout << "\n " << chamber ++ << ":";
      for( auto ve : v ) cout << " " << ve.fi;
    }
    cout << "\nIMBALANCE = " << setprecision(5) << fixed << imbalance << "\n\n";
  }
  return 0;
}
/* this shit returns a bad output for Batman's output in uDebug but it's still AC in UVa */
