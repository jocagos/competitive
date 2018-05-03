#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    int n, m;
    scanf("%d %d", &n, &m);
    if( n == 1 and m == 0 or n == 0 and m == 1 or n == 0 and m == 0 ){
      cout << "Yes" << endl;
      continue;
    }
    int adjMat[n][m];
    for( int i = 0; i < n; ++i ){
      for( int j = 1; j <= m; ++j ){
	scanf("%d", &adjMat[i][j%m]);
      }
    }
    bool valid = true;
    for( int i = 0; i < min(m, n); ++i ) if( adjMat[i][i] ) valid = false;
    for( int i = 0; i < n; ++i ){
      for( int j = 0; j < m; ++j ){
	if( i == j ) continue;
	
      }
    }
  }
  return 0;
}
