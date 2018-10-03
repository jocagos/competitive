#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
  int t, adjMat[11][31];
  scanf("%d", &t);
  while(t--){
    int n, m;
    bool valid = true;
    scanf("%d %d", &n, &m);
    for( int i = 0; i < n; ++i ){
      for( int j = 0; j < m; ++j ){
	scanf("%d", &adjMat[i][j]);
      }
    }
    for( int i = 0; i < m; ++i ){
      int sum = 0;
      for( int j = 0; j < n; ++j ){
	sum += adjMat[j][i];
      }
      if( sum != 2 ) valid = false;
    }
    bool cons[11][11];
    memset(cons, false, sizeof cons );
    if( valid ){
      for( int i = 0; i < m and valid; ++i ){
	int f, s, j = 0;
	while( adjMat[j++][i] != 1 );
	f = j - 1;
	while( adjMat[j++][i] != 1 );
	s = j - 1;
	if( !cons[f][s] ) cons[s][f] = cons[f][s] = true;
	else valid = false;
      }
    }
    if( valid ) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}
