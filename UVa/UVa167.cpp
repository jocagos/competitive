#include <iostream>
#include <vector>

using namespace std;

int backtrack( int **mat, int score );

int main(){
  int mat[8][8];
  int t;
  scanf("%d", &t);
  while( t -- ){
    for( int i = 0; i < 8; ++ i ){
      for( int j = 0; j < 8; ++ j ) scanf("%d", &mat[i][j]);
    }
    int score = backtrack( mat, 0 );
  }
  
  return 0;
}

int backtrack( int **mat, int score ){
  int sum = 0;
}
