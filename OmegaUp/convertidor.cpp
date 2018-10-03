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

unordered_map<char, int> c2i{ { 'A' , 1 }, { 'B' , 2 }, { 'C' , 3 }, { 'D' , 4 }, { 'E' , 5 }, { 'F' , 6 }, { 'G' , 7 }, { 'H' , 8 }, { 'I' , 9 }, { 'J' , 10 }, { 'K' , 11 }, { 'L' , 12 }, { 'M' , 13 }, { 'N' , 14 }, { 'O' , 15 }, { 'P' , 16 }, { 'Q' , 17 }, { 'R' , 18 }, { 'S' , 19 }, { 'T' , 20 }, { 'U' , 21 }, { 'V' , 22 }, { 'W' , 23 }, { 'X' , 24 }, { 'Y' , 25 }, { 'Z' , 26 } };

unordered_map<int, char> i2c{ { 0, 'Z' }, { 1, 'A' }, { 2 , 'B' }, { 3 , 'C' }, { 4 , 'D' }, { 5 , 'E' }, { 6 , 'F' }, { 7 , 'G' }, { 8 , 'H' }, { 9 , 'I' }, { 10 , 'J' }, { 11 , 'K' }, { 12 , 'L' }, { 13 , 'M' }, { 14 , 'N' }, { 15 , 'O' }, { 16 , 'P' }, { 17 , 'Q' }, { 18 , 'R' }, { 19 , 'S' }, { 20 , 'T' }, { 21 , 'U' }, { 22 , 'V' }, { 23 , 'W' }, { 24 , 'X' }, { 25 , 'Y' }, { 26 , 'Z' } };

unsigned long long ullpow( unsigned long long base, unsigned long long exp ){
  if( base == 0ULL ) return 0ULL;
  if( exp == 0ULL ) return 1ULL;
  if( base == 1ULL or exp == 1ULL ) return base;
  unsigned long long ans = 1ULL;
  while( exp > 0 ){
    if( exp & 1ULL ) ans = ans * base;
    base *= base;
    exp >>= 1ULL;
  }
  return ans;
}

int main(void){
  int t;
  fastio;
  cin >> t;
  if( t == 1 ){ // str to int
    unsigned long long val = 0;
    long exp = 0;
    string s;
    cin >> s;
    reverse( all( s ) );
    for( auto c : s ){
      val += c2i[c] * ullpow( 26ULL, exp ++ );
    }
    cout << val << '\n';
  }
  else if( t == 0 ){ // int to str
    unsigned long long val = 0, mod = 26;
    cin >> val;
    string s;
    while( val ){
      s += i2c[val % mod];
      val -= (val % mod == 0 ? 26 : val % mod );
      val /= 26;
    }
    reverse( all( s ) );
    cout << s << '\n';
  }
  return 0;
}
