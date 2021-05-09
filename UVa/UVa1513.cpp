#include <cstdio>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
constexpr int MAXN = 200020;
int keys[MAXN] {};

void init( int n = MAXN ){
  for( int i {}; i <= n; ++ i )
    keys[i] = i;
}

int main(){
  int tc {}, KEY {};
  scanf("%d", &tc);
  while( tc -- ){
    int n {}, m {}, val {};
    scanf("%d %d", &n, &m);
    init( n );
    ordered_set<int> treap( keys + 1, keys + n );
    for( int i = 0; i < m; ++ i ){
      scanf("%d", &val);
      if( i )
	printf(" ");
      printf("%lu", treap.order_of_key( keys[val] ));
      treap.erase( keys[val] );
      treap.insert( KEY );
      keys[val] = KEY;
      -- KEY;
    }
    printf("\n");
  }
  return 0;
}
