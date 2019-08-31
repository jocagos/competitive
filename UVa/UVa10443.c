#include <stdio.h>
#include <string.h>

int main(){
  int t, i, j, k;
  char grid[100][100];
  scanf("%d ", &t);
  while(t--){
    int r, c, n;
    char tmp;
    scanf("%d %d %d ", &r, &c, &n);
    for( i = 0; i < r; ++i ){
      for( j = 0; j < c; ++j ) grid[i][j] = getchar();
      getchar(); /* skip \n */
    }

    for( k = 0; k < n; ++k ){
      for( i = 0; i < r; ++i ){
	for( j = 0; j < c; ++j ){
	  if( i > 0 ){
	    if( j > 0 ){
	      /* */
	    }
	  }
	}
      }
    }
    
    if( t ) putchar('\n');
  }
  return 0;
}
