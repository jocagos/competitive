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

int main(void){
  int tc = 1, missing = 0;
  string s, t, u, _s, _t, _u, ans, val;
  bool parentMinus = false, kidMinus = false, twoParents = false;
  set<string> values;
  fastio;
  unordered_map<string, string> keyParents { {"A+A", "A+A"}, {"A+O", "A+A"}, {"O+A", "A+A"}, {"A+B", "A+B"}, {"B+A", "A+B"}, {"A+AB", "A+AB"}, {"B+AB", "A+AB"}, {"AB+A", "A+AB"}, {"AB+B", "A+AB"}, {"AB+AB", "A+AB"}, {"B+B", "B+B"}, {"B+O", "B+B"}, {"O+B", "B+B"}, {"AB+O", "AB+O"}, {"O+AB", "AB+O"}, {"O+O", "O+O"} };
  unordered_map<string, string> keyOrphans { {"A+A", "A+A"}, {"B+B", "A+A"}, {"AB+A", "A+A"}, {"AB+B", "A+A"}, {"A+B", "A+B"}, {"A+AB", "A+B"}, {"O+B", "A+B"}, {"A+O", "A+O"}, {"B+O", "A+O"}, {"O+O", "A+O"}, {"B+A", "B+A"}, {"B+AB", "B+A"}, {"O+A", "B+A"}, {"AB+AB", "AB+AB"}, {"AB+O", "AB+O"}, {"O+AB", "AB+O"} };
  unordered_map<string, vector<string>> parents { {"A+A", {"A", "O"} }, {"A+B", {"A", "B", "AB", "O" } }, {"A+AB", {"A", "B", "AB"} }, {"B+B", {"B", "O"} }, {"AB+O", {"A", "B"} }, {"O+O", {"O"}} };
  unordered_map<string, vector<string>> orphans { {"A+A", {"A", "B", "AB", "O"} }, {"A+B", {"B", "AB"} }, {"A+O", {"A", "B", "O"} }, {"B+A", {"A", "AB"} }, {"AB+AB", {"A", "B", "AB"} }, {"AB+O", {} } };
  while( cin >> s ){
    if( s == "" ) continue;
    if( s == "E" ){ cin >> t >> u; break; }
    cin >> t >> u;
    values.clear();
    ans = "";
    if( s.substr( 0, 1 ) == "?" ){
      missing = 0;
      parentMinus = (t[t.length() - 1] == '-');
      kidMinus = (u[u.length() - 1] == '-');
      twoParents = false;
      _t = t.substr( 0, t.length() - 1 );
      _u = u.substr( 0, u.length() - 1 );
    }
    else if( t.substr( 0, 1 ) == "?" ){
      missing = 1;
      parentMinus = (s[s.length() - 1] == '-');
      kidMinus = (u[u.length() - 1] == '-');
      twoParents = false;
      _s = s.substr( 0, s.length() - 1 );
      _u = u.substr( 0, u.length() - 1 );
    }
    else if( u.substr( 0, 1 ) == "?" ){
      missing = 2;
      twoParents = true;
      parentMinus = (s[s.length() - 1] == '-');
      kidMinus = (t[t.length() - 1] == '-');
      _t = t.substr( 0, t.length() - 1 );
      _s = s.substr( 0, s.length() - 1 );
    }
    if( missing == 2 ){ // Both parents given, easy answer for sign
      // ans += "{";
      // simply check the sum, no impossible here
      for( int i = 0; i < parents[keyParents[_s + "+" + _t]].size(); ++ i  ){
	val = parents[keyParents[_s + "+" + _t]][i];
	if( !parentMinus or !kidMinus ) values.insert( val + "+" );//ans += val + "+, ";
	values.insert( val + "-" );//ans += val + "-" + (i + 1 == parents[keyParents[_s + "+" + _t]].size() ? "" : ", ");
      }
      // ans += "}";
    }
    else{
      // Check parent and result, impossible here if
      // AB + X = O
      // O + X = AB
      ans += "{";
      if( orphans[keyOrphans[(missing ? _s : _t) + "+" + _u]].size() > 0 ){
	for( int i = 0; i < orphans[keyOrphans[(missing ? _s : _t) + "+" + _u]].size(); ++ i  ){
	  val = orphans[keyOrphans[(missing ? _s : _t) + "+" + _u]][i];
	  values.insert ( val + "+" );
	  if( !parentMinus and kidMinus ) values.insert( ", " + val + "-" );
	  // ans += (i + 1 == orphans[keyOrphans[(missing ? _s : _t) + "+" + _u]].size() ? "" : ", ");
	}
	ans += "}";
      }
      else ans = "IMPOSSIBLE";
    }
    cout << "Case " << tc ++ << ": " << (missing == 0 ? ans : s) << " " << (missing == 1 ? ans : t) << " " << (missing == 2 ? ans : u) << '\n';
    
  }
  return 0;
}
