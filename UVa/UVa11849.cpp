#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m;
  while( scanf("%d %d", &n, &m), n | m ){
    unordered_map<long, int> cd;
    int c = 0;
    long tmp;
    for( int i = 0; i < n; ++i ){
      scanf("%ld", &tmp);
      cd[tmp] = 1;
    }
    for( int i = 0; i < m; ++i ){
      scanf("%ld", &tmp);
      if( cd[tmp] == 1 ) c++;
    }
    printf("%d\n", c);
  }
  return 0;
}
