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
template <class T> using maxHeap = __gnu_pbds::priority_queue<T, less<T>, pairing_heap_tag>;
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

int main(void){
  int t, k;
  char c;
  cin >> t;
  while( t-- ){
    cin >> k;
    //vector<vector<char>> first(5, vector<char>(6)), second(5, vector<char>(6));
    vector< set< char > > first(5), second(5);
    REP(i, 12){
      REP(j, 5){
	cin >> c;
	if( i < 6 ) first[j].insert(c);
	else second[j].insert(c);
	/*
	if( i < 6 ) cin >> first[j][i];
	else cin >> second[j][i-6];
	*/
      }
    }
    // added
    vector<vector<char>> chars(5, vector<char>(6) );
    REP(i, 5){
      auto it = set_intersection( all(first[i]), all(second[i]), chars[i].begin() );
      chars[i].resize( it - chars[i].begin() );
      /*sort( all(first[i]) );
	sort( all(second[i]) );*/
    }
    // set<string> left, right;
    // added
    oSet<string> answers;
    for( auto i : chars[0] ){
      for( auto j : chars[1] ){
	for( auto k : chars[2] ){
	  for( auto l : chars[3] ){
	    for( auto m : chars[4] ){
	      string s {i, j, k, l, m};
	      answers.insert(s);
	    }
	  }
	}
      }
    }
    auto a = answers.find_by_order(k-1);
    if( a == answers.end() ) cout << "NO" << endl;
    else cout << *a << endl;
    /*
    REP( i, 6 ){
      REP( j, 6 ){
	REP( k, 6 ){
	  REP( l, 6 ){
	    REP( m, 6 ){
	      
	      string s {first[0][i], first[1][j], first[2][k], first[3][l], first[4][m]};
	      left.insert(s);
	      string t {second[0][i], second[1][j], second[2][k], second[3][l], second[4][m]};
	      right.insert(t);
	    }
	  }
	}
      }
    }
    
    vector<string> matches(100000);
    auto it = set_intersection( all(left), all(right), matches.begin() );
    matches.resize(it - matches.begin() );
    if( k <= matches.size() ) cout << matches[k-1] << endl;
    else cout << "NO" << endl;
    */
  }
  return 0;
}
