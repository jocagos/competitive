#include <iostream>
#include <vector>

using namespace std;

int main(){
  int v;
  scanf("%d", &v);
  while( v ){
    vector<int> vals(v);
    for( int i = 0; i < v; ++ i ) scanf("%d", &vals[i] );
    for( int i = 0; i < v - 5; ++ i ){
      for( int j = i+1; j < v - 4; ++ j ){
	for( int k = j + 1; k < v - 3; ++ k ){
	  for( int l = k + 1; l < v - 2; ++ l ){
	    for( int m = l + 1; m < v - 1; ++ m ){
	      for( int n = m + 1; n < v; ++ n ){
		printf("%d %d %d %d %d %d\n", vals[i], vals[j], vals[k], vals[l], vals[m], vals[n] );
	      }
	    }
	  }
	}
      }
    }
    scanf("%d", &v);
    if( v ) printf("\n");
  }
  return 0;
}
