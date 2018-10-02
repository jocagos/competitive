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

unordered_multimap<string, pair<string, pair<int, int>>> hashes;
unordered_map<string, vector<pair<string, int>>> EdgeList;
vector<pair<string, string>> queries;
unordered_map<string, bool> visited;
string key;

void dfs( );

int main(void){
  string line;
  fastio;  
  while( getline( cin, line ) ){
    istringstream iss( line );
    if( line[0] == '!' ){ // assertion
      string s, t, dummy;
      int a, b, g;
      // get rid of '!' and '=' then continue
      iss >> dummy >> a >> s >> dummy >> b >> t; // easily read line!
      g = gcd( a, b );
      EdgeList[s].EB( t, a / g ); // a bidirectional edge is composed of two edges
      EdgeList[t].EB( t, b / g );
      // hashes.insert( { s, { t, { a/g, b/g } } } );
      // hashes.insert( { t, { s, { b/g, a/g } } } );
      visited[s] = false; // add key to know it
      visited[t] = false; // add key to know it
    }
    else if( line[0] == '?' ){ // query
      string dummy, s, t;
      iss >> dummy >> s >> dummy >> t;
      for( auto &x : visited ) x.se = false; // we have not visited anything yet
      // time to do a dfs!
      bool connected = false;
      int a, b, k, start; a = b = k = start = 1;
      // implicit dfs here
      auto vals = hashes.equal_range( s ); // find first range
      for( auto it = vals.fi; it != vals.se; ++ it ){
	if( );
      }
    }
    else{ // reaching a dot
      break;
    }
  }
  return 0;
}

void dfs( string s, string target, int a, int b ){
  
}
