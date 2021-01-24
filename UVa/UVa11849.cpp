/* Usual way: unordered_set/unordered_map (HashSet/HashTable)
#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m;
  while( scanf("%d %d", &n, &m), n | m ){
    unordered_set<long> cd;
    int c = 0;
    long tmp;
    for( int i = 0; i < n; ++i ){
      scanf("%ld", &tmp);
      cd.emplace( tmp );
    }
    for( int i = 0; i < m; ++i ){
      scanf("%ld", &tmp);
      if( cd.find( tmp ) != cd.end() ) c++;
    }
    printf("%d\n", c);
  }
  return 0;
}
*/
// New way: set with emplace_hint
#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m;
  while( scanf("%d %d", &n, &m), n | m ){
    set<long> cd;
    int c = 0;
    long tmp;
    for( int i = 0; i < n; ++i ){
      scanf("%ld", &tmp);
      cd.emplace_hint( cd.end(), tmp );
    }
    for( int i = 0; i < m; ++i ){
      scanf("%ld", &tmp);
      if( cd.find( tmp ) != cd.end() ) c++;
    }
    printf("%d\n", c);
  }
  return 0;
}
