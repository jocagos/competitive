#include <iostream>
#include <set>

using namespace std;

int main(){
  set<long> cd;
  int n, m;
  while( scanf("%d %d", &n, &m), n | m ){
    cd.clear();
    int c = 0;
    long tmp;
    for( int i = 0; i < n; ++i ){
      scanf("%ld", &tmp);
      cd.insert(tmp);
    }
    for( int i = 0; i < m; ++i ){
      scanf("%ld", &tmp);
      if( cd.find(tmp) != cd.end() ) c++;
    }
    printf("%d\n", c);
  }
  return 0;
}
