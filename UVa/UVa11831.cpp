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

// easy access/use
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define view(x) cout << #x << ": " << x << '\n';
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

unordered_map<char, char> D { {'N', 'E'}, {'E', 'S'}, {'S', 'W'}, {'W', 'N'} },
			  E { {'N', 'W'}, {'W', 'S'}, {'S', 'E'}, {'E', 'N'} },
			  F { {'N', 'N'}, {'S', 'S'}, {'L', 'E'}, {'O', 'W'} };     
constexpr char FORWARD = 'F', LEFT = 'E', RIGHT = 'D', BLOCK = '#', STICKER = '*', PATH = '.';
ii pos;
char face, arena[101][101];
bool read;

int main(void){
  int n, m, s;
  string line;
  fastio;
  while( getline( cin, line ) ){
    read = false;
    face = 'Z';
    pos = { -1, -1 };
    istringstream iss( line );
    iss >> n >> m >> s;
    if( n | m | s ){
      REP( i, n ){
	getline( cin, line );
	REP( j, m ){
	  arena[i][j] = line[j];
	  if( !read and isIn( line[j], { 'N', 'S', 'L', 'O' } ) ){
	    read = true;
	    face = F[line[j]];
	    pos = { i, j };
	  }
	}
      }
      getline( cin, line );
      int count = 0;
      REP( i, s ){
	if( line[i] == LEFT ) face = E[face];
	else if( line[i] == RIGHT ) face = D[face];
	else if( line[i] == FORWARD ){
	  if( face == 'N' ){
	    if( pos.fi > 0 ){
	      if( arena[pos.fi - 1][pos.se] == STICKER ){
		arena[pos.fi][pos.se] = PATH;
		++ count;
		-- pos.fi;
		arena[pos.fi][pos.se] = face;
	      }
	      else if( arena[pos.fi - 1][pos.se] == PATH ){
		arena[pos.fi][pos.se] = PATH;
		-- pos.fi;
		arena[pos.fi][pos.se] = face;
	      }
	    }
	  }
	  else if( face == 'S' ){
	    if( pos.fi < n - 1 ){
	      if( arena[pos.fi + 1][pos.se] == STICKER ){
		arena[pos.fi][pos.se] = PATH;
		++ count;
		++ pos.fi;
		arena[pos.fi][pos.se] = face;
	      }
	      else if( arena[pos.fi + 1][pos.se] == PATH ){
		arena[pos.fi][pos.se] = PATH;
		++ pos.fi;
		arena[pos.fi][pos.se] = face;
	      }
	    }
	  }
	  else if( face == 'E' ){
	    if( pos.se < m - 1 ){
	      if( arena[pos.fi][pos.se + 1] == STICKER ){
		arena[pos.fi][pos.se] = PATH;
		++ count;
		++ pos.se;
		arena[pos.fi][pos.se] = face;
	      }
	      else if( arena[pos.fi][pos.se + 1] == PATH ){
		arena[pos.fi][pos.se] = PATH;
		++ pos.se;
		arena[pos.fi][pos.se] = face;
	      }
	    }
	  }
	  else if( face == 'W' ){
	    if( pos.se > 0 ){
	      if( arena[pos.fi][pos.se - 1] == STICKER ){
		arena[pos.fi][pos.se] = PATH;
		++ count;
		-- pos.se;
		arena[pos.fi][pos.se] = face;
	      }
	      else if( arena[pos.fi][pos.se - 1] == PATH ){
		arena[pos.fi][pos.se] = PATH;
		-- pos.se;
		arena[pos.fi][pos.se] = face;
	      }
	    }
	  }
	}
      }
      cout << count << '\n';
    }
    else break;
  }
  return 0;
}
