#include <iostream>

using namespace std;

int main(){
  int n, m, flag[101][101], i, j;
  bool iso = true;
  scanf("%d %d", &n, &m);
  for( i = 0; i < n and iso; ++ i ){
    for( j = 0; j < m and iso; ++ j ){
      scanf("%1d", &flag[i][j]);
      if( j >= 1 and flag[i][j-1] != flag[i][j] ) iso = false;
      if( i >= 1 and flag[i-1][j] == flag[i][j] ) iso = false;
    }
  }
  if( iso ) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
