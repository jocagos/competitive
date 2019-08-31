// all this for nothing! check UVa10389-2.cpp instead if you're looking for the solution

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using i64 = unsigned long long;
using ld = long double;
// using ii = tuple<int, int>; // or pair<int, int>
// using dd = tuple<double, double>; // or pair< double, double >
template <class T> using twin = tuple<T, T>;
template <class T> using triad = tuple<T, T, T>;
template <class T> using quad = tuple<T, T, T, T>;
template <class T, class U = T, class V = T>
using mtriad = tuple<T, U, V>;

template <class T, class U = T, class V = T, class W = T>
using mquad = tuple<T, U, V, W>;

using vi = vector<int>;
using vs = vector<string>;
using vd = vector<double>;
using vld = vector<ld>;
template <class T, class U = T>
using vtwin = vector<tuple<T, U>>;
template <class T, class U = T, class V = T>
using vtriad = vector<tuple<T, U, V>>;
template <class T, class U = T, class V = T, class W = T>
using vquad = vector<tuple<T, U, V, W>>;

// minHeap, BinomialHeap and FibonacciHeap for later use, policy based data structures
/* NOTES:
`pairing_heap_tag` is good for non-primitive data types like `string`
`binary_heap_tag` is good for primitive data types
`binomial_heap_tag` is good for responsiveness
`rc_binomial_heap_tag` has more responsiveness at the cost of worse constants
`thin_heap_tag` is good for graph algorithms (FibonacciHeap)
 */
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
constexpr twin<int> n8[8] = { { -1, -1 }, // upper left
			      { -1, 0 }, // upper middle
			      { -1, 1 }, // upper right
			      { 0, -1 }, // center left
			      { 0, 1 }, // center right
			      { 1, -1 }, // lower left
			      { 1, 0 }, // lower middle
			      { 1, 1 } // lower right
                     },
                     n4[4] = { { -1, 0 }, // down
			       { 0, -1 }, // left
			       { 0, 1 }, // right
			       { 1, 0 } // up
		     };
constexpr triad<int> n3d[] = { { 0, -1, 0 }, // up
		     { 0, 1, 0 }, // down
		     { -1, 0, 0 }, // left
		     { 1, 0, 0 }, // right
		     { 0, 0, -1 }, // backward
		     { 0, 0, 1 } // forward
};
constexpr bool V = true, NV = false;
// /* slaps vector */ This bad boy can hold SO MANY
// values to compare a value to!
template<typename T>
bool is_in( T const &value, std::vector<T>& v ){
  return std::find( v.begin(), v.end(), value ) != v.end();
}
// /* slaps initializer_list */ And THIS bad boy can hold
// ANY initializer_list with the same type as the value
// to look forward!
template<typename T>
bool is_in( T const &value, std::initializer_list<T> v ){
  return std::find( v.begin(), v.end(), value ) != v.end();
}

/*
 * Only valid if T, U, V are trivially compared with operator< or operator<=
 */

template <typename T, typename U, typename V>
inline bool in( T a, U b, V x ){
  return (a <= x) and (x <= b);
}

template <typename T, typename U, typename V>
inline bool inx( T a, U b, V x ){
  return (a <= x) and (x < b);
}

template <typename T, typename U, typename V>
inline bool xin( T a, U b, V x ){
  return (a < x) and (x <= b);
}

template <typename T, typename U, typename V>
inline bool xinx( T a, U b, V x ){
  return (a < x) and (x < b);
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

// can't remove these macros
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define viewStr(s) cout << #s << ": >" << (s) << "<" << endl
#define view(x) cout << #x << ": " << x << endl
#define sz(c) (int)((c).size())
#define all(c) (c).begin(), (c).end()
// pretty useful though hard to make a template out of it that works
// with almost any type without casts and so
// it might work:
/*
  template <typename T, typename U, typename V>
  inline bool in( T a, U b, V x ){
    return a <= x and x <= b;
  }
 */
// easy access/use
// #define in( a, b, x ) ( (a) <= (x) and (x) <= (b) )
#define justN(c, n) (c).begin(), (c).begin() + n
#define sq(a) (a) * (a)
#define fi first
#define se second
#define g0 get<0>
#define g1 get<1>
#define g2 get<2>
#define g3 get<3>
#define g4 get<4>
#define g5 get<5>
#define g6 get<6>
#define g7 get<7>
#define g8 get<8>
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
constexpr int MAXN = 250;
twin<int> source, target;
int tc;
string line;
vector<twin<int>> points( MAXN );
map<twin<int>, int> p2i;
vector<double> dist( MAXN );
vi lines( MAXN );
vi cases 
  {
   5, 11, 13, 15, 21, 27, 29, 31, 33, 39, 43, 49, 57, 59, 65, 69, 71, 73, 79, 81, 85, 87, 89, 91, 93, 95, 103, 105, 107, 109, 111, 115, 119, 121, 123, 125, 131, 133, 135, 139, 143, 151, 159, 161, 165, 167, 171, 177, 179, 183, 185, 187, 189, 191, 197, 201, 203, 205, 217, 219, 223, 225, 227, 229, 233, 237, 239, 241, 243, 249, 255
  }
;

// who needs an adjlist when you can generate it on the go

int main(void){
  fastio;
  getline( cin, line ); // read tc
  tc = stoi( line );
  getline( cin, line );
  int TEST_CASE = 1;
  while( tc -- ){
    double minutes = 0;
    line = "-1";
    int pidx = 0, what_line = -2;
    bool first = false;
    while( getline( cin, line ), line != "" ){ // read until blank line
      if( !first ){
	istringstream iss1( line );
	int a, b, c, d;
	iss1 >> a >> b >> c >> d;
	source = { a, b };
	target = { c, d };
	points[pidx] = source;
	lines[pidx] = what_line;
	++ what_line;
	p2i[source] = pidx;
	// cerr << "Assigned (" << a << "," << b << ") as source with idx = " << pidx << endl;
	++ pidx;
	points[pidx] = target;
	lines[pidx] = what_line;
	++ what_line;
	p2i[target] = pidx;
	// cerr << "Assigned (" << c << "," << d << ") as target with idx = " << pidx << endl;
	++ pidx;
	first = true;
      }
      else{
	istringstream iss( line );
	int a, b;
	iss >> a >> b;
	while( a != -1 and b != -1 ){
	  points[pidx] = { a, b };
	  lines[pidx] = what_line;
	  p2i[points[pidx]] = pidx;
	  // cerr << "Assigned point (" << a << ", " << b << ") to idx = " << pidx << endl;
	  ++ pidx;
	  iss >> a >> b;
	}
	++ what_line;
      }
    }
    dist.assign( 250, LLINF );
    dist[0] = 0;
    bool logging = false;
    if( is_in<int>( TEST_CASE * 2 - 1, cases ) ){
      cerr << endl << "LOGGING IS ON FOR TEST CASE " << TEST_CASE << endl << "POINTS:" << endl;
      REP( i, pidx ) cerr << "Point " << i + 1 << " is (" << get<0>( points[i] ) << ", " << get<1>( points[i] ) << ")" << endl;
      cerr << endl << endl << "CHECKING ALGORITHM:" << endl;
      logging = true;
    }
    // REP( i, pidx ){
    //   cerr << "Dist from " << i << " = (" << get<0>( points[i] ) << ", " << get<1>( points[i] ) << ") to source = (" << get<0>( points[0] ) << ", " << get<1>( points[0] ) << ") is " << dist[i] << endl;
    // }
    std::priority_queue< tuple<double, int, int>, vector<tuple<double, int, int>>, greater<tuple<double, int, int>> > pq;
    tuple<double, int, int> pp { 0.0, get<0>( source ), get<1>( source ) };
    if( logging ) cerr << "SOURCE PUSHED WAS (" << get<0>( source ) << ", " << get<1>( source ) << ") AND TARGET IS (" << get<0>( target ) << ", " << get<1>( target ) << ")" << endl;
    pq.push( pp );
    while( not pq.empty() ){
      tuple<double, int, int> front = pq.top();
      if( logging ) cerr << "TOP IS (" << get<0>( front ) << ", " << get<1>( front ) << ", " << get<2>( front ) << ")" << endl;
      pq.pop();
      double D = get<0>( front );
      twin<int> U { get<1>( front ), get<2>( front ) };
      if( logging ) cerr << "dist[(" << get<0>( U ) << ", " << get<1>( U ) << ")(" << p2i[U] << ")] is " << dist[p2i[U]] << endl;
      if( D > dist[p2i[U]] ) continue;
      if( logging ) cerr << D << " isn't higher than " << dist[p2i[U]] << endl;
      for( int i = 0; i < pidx; ++ i ){
	if( p2i[U] == i ) continue; // avoid self loops
	if( logging ) cerr << "Checking (" << get<0>( points[i] ) << ", " << get<1>( points[i] ) << ")" << endl;
	tuple<double, int, int> next { (lines[i] == lines[p2i[U]] ? 1 : 4 ) * hypot( get<0>( U ) - get<0>( points[i] ), get<1>( U ) - get<1>( points[i] ) ), get<0>( points[i] ), get<1>( points[i] ) };
	twin<int> _v = points[i];
	if( logging ){
	  cerr << "dist[(" << get<0>( U ) << ", " << get<1>( U ) << ")(" << p2i[U] << ")] = " << dist[p2i[U]] << endl
	       << "get<0>( next ) = " << get<0>( next ) << endl
	       << "dist[(" << get<0>( _v ) << ", " << get<1>( _v ) << ")(" << p2i[_v] << ")] = " << dist[p2i[_v]] << endl;
	}
	if( dist[p2i[U]] + get<0>( next ) < dist[p2i[_v]] ){
	  if( logging ) cerr << "COND IS TRUE" << endl << "NEW DIST TO (" << get<0>( _v ) << ", " << get<1>( _v ) << ")(" << p2i[_v] << ") = " << dist[p2i[U]] + get<0>( next ) << endl << "PUSHED (" << get<0>( next ) << "," << get<1>( next ) << ", " << get<2>( next ) << ")" << endl;
	  dist[p2i[_v]] = dist[p2i[U]] + get<0>( next );
	  pq.push( next );
	}
      }
    }
    minutes = int(dist[p2i[target]]*6/4000+0.5);
    cout << minutes << endl;
    if( tc ) cout << endl;
    TEST_CASE ++;
  }
  return 0;
}
