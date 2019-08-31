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

/* FAST I/O for integers
 * USE: just add the characters to `buf` and check if you are close to overflow
 * and if so just print `buf` then reset iterator to buf.
char buf[10000000];
constexpr int ZERO = 0, NEWLINE = 1, WHITESPACE = 2;

// let's try it again lmao
int next_int( void ){
  char c;
  do{ c = getchar_unlocked(); } while( c != '-' and !isdigit( c ) );
  bool neg = (c == '-');
  int r = neg ? 0 : c - '0';
  while( isdigit( c = getchar_unlocked() ) ) r = 10 * r + (c - '0');
  return neg ? -r : r;
}

int print_int( int N, int idx, int nd = ZERO ){
  if( N < 10 ) buf[idx ++] = N + '0';
  else{
    buf[idx ++] = (N / 10) + '0';
    buf[idx ++] = N % 10 + '0';
  }
  if( nd == WHITESPACE ) buf[idx ++] = ' ';
  else if( nd == NEWLINE ) buf[idx ++] = '\n';
  else buf[idx ++] = '\0';
  return idx;
}
 */

// easy access/use
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define prepare( cont, n ) (cont).clear(); (cont).resize( n )
#define viewStr(s) cout << #s << ": >" << (s) << "<" << endl
#define view(x) cout << #x << ": " << x << endl
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
constexpr int MAXN = 1010, MAXM = 18280, sec = 26 * 26;
int m, n;
vector<vector<int>> g;
// vector<bool> vis;
vi ts, degree, d;

// void toposort( int u ){
//   vis[u] = V;
//   for( auto v : g[u] ){
//     if( not vis[v] ) toposort( v );
//   }
//   ts.EB( u );
// }

inline int coord( int row, int col ){
  return row * m + col;
}

inline int convert( string s ){
  int ans = 0;
  if( s.length() == 3 ){
    ans += (s[0] - 'A' + 1) * sec;
    ans += (s[1] - 'A' + 1) * 26;
    ans += (s[2] - 'A' + 1);
  }
  else if( s.length() == 2 ){
    ans += (s[0] - 'A' + 1) * 26;
    ans += (s[1] - 'A' + 1);
  }
  else ans += (s[0] - 'A' + 1);
  return ans - 1;
}

int main(void){
  int tc;
  string line;
  fastio;
  // getline( cin, line );
  cin >> line;
  tc = stoi( line );
  while( tc -- ){
    string s, t;
    // parse m, n
    // getline( cin, line );
    // while( line == "" ) getline( cin, line );
    // istringstream _ss( line );
    cin >> s >> t;
    m = stoi( s ), n = stoi( t );// _ss >> m >> n;
    // assign memory
    // memo.assign( n, vi( m, 0 ) );
    d.assign( m * n, 0 );
    g.assign( m * n, vi() );
    // vis.assign( m * n, false );
    ts.assign( m * n, -1 );
    degree.assign( m * n, 0 );
    // parse values
    REP( i, n ){
      // read line-by-line fashion
      // getline( cin, line );
      // while( line == "" ) getline( cin, line );
      // istringstream iss( line );
      // for every value in the line
      REP( j, m ){
	cin >> s;
	int _ = coord( i, j );
	// cout << "(" << i << ", " << j << ") = d[" << _ << "] = ";
	// iss >> s; // get it
	// cout << s << endl;
	if( s[0] == '=' ){ // formula
	  // then parse it
	  t = s.substr( 1 ); // remove the '='
	  // cout << "Removed '=' and t = " << t << endl;
	  while( t != "" ){ // now for every part of the formula
	    size_t idx = t.find( '+' ); // find the next '+'
	    string token = t.substr( 0, idx ); // tokenize
	    t = ( idx == string::npos ? "" : t.substr( idx + 1 ) ); // if there ae no '+' just make it null
	    // parse col code and row then connect
	    int numIdx = 0; // let's read the value
	    // find where the first number is
	    while( not isdigit( token[numIdx] ) ) numIdx ++;
	    // then get the row, col values from the code
	    string col = token.substr( 0, numIdx ), row = token.substr( numIdx );
	    // then get them to int
	    int r = stoi( row ), c = convert( col );
	    // now set the requirements in the graph
	    g[coord( r - 1, c )].EB( _ );
	    // and set the value as 0
	    d[_] = 0;
	    // add to their degree
	    degree[ _ ] ++;
	  }
	}
	// value, just read it
	else d[ _ ] = stoi( s );
      } // end REP-j
    } // end REP-i
    // now let's just do a topological sort, since it's a DAG
    int tsIdx = 0;
    std::priority_queue<int, vector<int>, greater<int>> pq;
    REP( i, m * n ) if( not degree[i] ) pq.emplace( i );
    while( not pq.empty() ){
      int u = pq.top(); pq.pop();
      for( auto v : g[u] ){
	degree[v] --;
	if( not degree[v] ) pq.emplace( v );
	d[v] += d[u];
      }
      ts[tsIdx ++] = u;
    }
    // Now it's just a matter of printing
    REP( i, n ){
      REP( j, m ){
	int _ = coord( i, j );
	cout << d[_] << (j + 1 < m ? " " : "\n");
      }
    }
    // REP( i, m * n ){
    //   if( not v[u] ){
    // 	stack<int> st;
    // 	st.push( i );
    // 	while( not st.empty() ){
    // 	  int u = st.top();
    // 	  st.pop();
    // 	  vis[u] = V;
    // 	  for( auto v : g[u] ){
	    
    // 	  }
    // 	}
    //   }
    // }
    // void toposort( int u ){
    //   vis[u] = V;
    //   for( auto v : g[u] ){
    // 	if( not vis[v] ) toposort( v );
    //   }
    //   ts.EB( u );
    // }
  }
  return 0;
}
