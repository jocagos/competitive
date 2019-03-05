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
#define prtCntP(cnt) for( auto _ : cnt ) cout << "( " << _.first << ", " << _.second << " )\n";
#define view(x) cout << #x << ": " << x << endl;
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

int ________[66][66];
int _0xFFFF;

int _0x0047_0x0043_0x0044( int _0x0041, int _0x0042 ){
  while( _0x0041 and _0x0042 ){
    if( _0x0041 > _0x0042 ) _0x0041 %= _0x0042;
    else _0x0042 %= _0x0041;
  }
  return _0x0041 + _0x0042;
}

void dfs( int _0x0058, int _0x0059 ){
  int _0x0041, _0x0042, _0x0043, _0x0044, _0x0045, _0x0046, _0x0047;
  REP( _0x005A, _0xFFFF ){
    if( _0x0058 != _0x005A and ________[_0x0059][_0x005A] and !________[_0x0058][_0x005A] ){
      _0x0041 = ________[_0x0058][_0x0059];
      _0x0042 = ________[_0x0059][_0x0058];
      _0x0043 = ________[_0x0059][_0x005A];
      _0x0044 = ________[_0x005A][_0x0059];
      _0x0045 = _0x0047_0x0043_0x0044( _0x0042, _0x0043 );
      _0x0046 = _0x0043 / _0x0045;
      _0x0047 = _0x0042 / _0x0045;
      _0x0045 = _0x0047_0x0043_0x0044( _0x0041 * _0x0046, _0x0044 * _0x0047 );
      ________[_0x0058][_0x005A] = _0x0041 * _0x0046 / _0x0045;
      ________[_0x005A][_0x0058] = _0x0044 * _0x0047 / _0x0045;
      dfs( _0x0058, _0x005A );
    }
  }
}

int main(void){
  fastio;
  string line;
  map<string, int> _FEDCBA;
  _0xFFFF = 0;
  while( getline( cin, line ) ){
    if( line == "." ) break;
    istringstream iss( line );
    string type, _0x0051, _0x0052; // no need of a dummy str
    int _0x0041, _0x0042, _0x0058, _0x0059;
    iss >> type;
    if( type == "!" ){
      iss >> _0x0041 >> _0x0051 >> type >> _0x0042 >> _0x0052;
      if( _FEDCBA.find(_0x0051) == _FEDCBA.end() ) _FEDCBA[_0x0051] = _0xFFFF ++;
      if( _FEDCBA.find(_0x0052) == _FEDCBA.end() ) _FEDCBA[_0x0052] = _0xFFFF ++;
      _0x0058 = _FEDCBA[_0x0051], _0x0059 = _FEDCBA[_0x0052];
      int _0x0043 = _0x0047_0x0043_0x0044( _0x0041, _0x0042 );
      ________[_0x0058][_0x0059] = _0x0041 / _0x0043, ________[_0x0059][_0x0058] = _0x0042 / _0x0043;
    }
    else if( type == "?" ){
      iss >> _0x0051 >> type >> _0x0052;
      if( _FEDCBA.find(_0x0051) == _FEDCBA.end() ) _FEDCBA[_0x0051] = _0xFFFF ++;
      if( _FEDCBA.find(_0x0052) == _FEDCBA.end() ) _FEDCBA[_0x0052] = _0xFFFF ++;
      _0x0058 = _FEDCBA[_0x0051], _0x0059 = _FEDCBA[_0x0052];
      REP( _, _0xFFFF ){ if( ________[_0x0058][_] ) dfs( _0x0058, _ );}
      if( ________[_0x0058][_0x0059] ) cout << ________[_0x0058][_0x0059] << " " << _0x0051 << " = " << ________[_0x0059][_0x0058] << " " <<  _0x0052 << '\n';
      else cout << "? " << _0x0051 << " = ? " << _0x0052 << '\n';
    }
  }
  return 0;
}
