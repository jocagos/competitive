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
constexpr twin<int> n8[8] = { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } }, n4[4] = { { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 } };
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
#define in( a, b, x ) ( (a) <= (x) and (x) <= (b) )
#define justN(c, n) ( (c).begin(), (c).begin() + n )
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
  string s, ans;
  int k;
  bool possible = true;
  fastio;
  cin >> s >> k;
  int candies = 0, snowflakes = 0, real_length = 0;
  REP( i, (int)s.length() ){
    if( s[i] == '?' ) candies ++;
    else if( s[i] == '*' ) snowflakes ++;
    else real_length ++;
  }
  if( real_length == k ){
    REP( i, (int)s.length() ) if( s[i] != '?' and s[i] != '*' ) cout << s[i];
    return 0;
  }
  else if( real_length < k and not snowflakes ){
    cout << "Impossible";
    return 0;
  }
  else if( real_length > k and real_length - snowflakes - candies > k ){
    cout << "Impossible";
    return 0;
  }
  else if( real_length != k and not snowflakes and not candies ){
    cout << "Impossible";
    return 0;
  }
  else{
    if( real_length < k ){
      int d = k - real_length;
      REP( i, (int)s.length() ){
	if( s[i] == '*' ){
	  while( d ){
	    cout << s[i - 1];
	    d --;
	  }
	}
	else if( s[i] != '?' ) cout << s[i];
      }
    }
    else if( real_length > k ){
      int d = real_length - k;
      REP( i, (int)s.length() ){
	if( (s[i + 1] == '?' or s[i + 1] == '*' ) and d ) d --;
	else if( s[i] != '?' and s[i] != '*' ) cout << s[i];
      }
    }
  }
  // if( real_length < k ){
  //   // cout << "<" << endl;
  //   if( snowflakes == 0 ) possible = false;
  //   else{
  //     string t( k, 'a' );
  //     int t_idx = 0;
  //     for( int i = 0; i < (int)s.length(); ++ i ){
  // 	if( i + 1 < (int)s.length() and s[i + 1] == '*' ){
  // 	  while( k - real_length + 1 ){
  // 	    t[t_idx ++] = s[i];
  // 	    real_length ++;
  // 	  }
  // 	}
  // 	else if( s[i] != '*' and s[i] != '?' ) t[t_idx ++] = s[i];
  //     }
  //     ans = t;
  //   }
  // }
  // else if( real_length == k ){
  //   // cout << "=" << endl;
  //   string t( begin( s ), remove_if( begin( s ), end( s ), []( char c ){ return c == '?' or c == '*'; } ) );
  //   ans = t;
  // }
  // else{
  //   // cout << ">" << endl;
  //   if( real_length - k > candies + snowflakes ) possible = false;
  //   else{
  //     string t( k, 'a' );
  //     int t_idx = 0;
  //     for( int i = 0; i < (int)s.length(); ++ i ){
  // 	// cout << "t_idx = " << t_idx << endl;
  // 	if( real_length > k ){
  // 	  if( s[i] == '?' or s[i] == '*' ) continue;
  // 	  if( i + 1 < (int)s.length() and s[i + 1] != '?' and s[i + 1] != '*' ){
  // 	    // real_length --;
  // 	    t[t_idx ++] = s[i];
  // 	  }
  // 	  else{
  // 	    real_length --;
  // 	  }
  // 	}
  // 	else if( s[i] != '*' and s[i] != '?' ) t[t_idx ++] = s[i];
  //     }
  //     ans = t;
  //   }
  // }
  // if( real_length - candies - snowflakes > k ) possible = false;
  // else if( real_length < k and snowflakes == 0 ) possible = false;
  // else{
  //   ans = s;
  //   if( real_length < k ){
  //     // cout << "<" << endl;
  //     int pos = ans.find( '*' );
  //     char c = ans[pos - 1];
  //     string f( k - real_length, c );
  //     f = ans.substr( 0, pos ) + f + ans.substr( pos );
  //     string tmp( begin( f ), remove_if( begin( f ), end( f ), []( char c ){ return c == '?' or c == '*'; } ) );
  //     ans = tmp;
  //   }
  //   else if( real_length == k ){
  //     // cout << "=" << endl;
  //     // remove( begin( ans ), end( ans ), '?' );
  //     // remove( begin( ans ), end( ans ), '*' );
  //     string t( ans.begin(), remove_if( begin( ans ), end( ans ), []( char c ){ return c == '?' or c == '*'; } ) );
  //     ans = t;
  //   }
  //   else{
  //     // cout << ">" << endl;
  //     int pos = 0;
  //     string tmp;
  //     while( real_length > k ){
  // 	int q = ans.find_first_of( "?*" );
  // 	tmp += ans.substr( pos, q - pos - 1 );
  // 	pos = q;
  // 	real_length --;
  //     }
  //     tmp += ans.substr( pos + 1 );
  //     remove_if( begin( tmp ), end( tmp ), []( char c ){ return c == '?' or c == '*'; } );
  //     string t( tmp.begin(), tmp.begin() + k );
  //     ans = t;
  //   }
  // }
  // if( not possible ) ans = "Impossible";
  // cout << ans << '\n';
  return 0;
}
