#include<iostream>
using namespace std;

int n, d, l, r, c;
int grid[10][10];
char ans = 'Y';

int main(){
  cin >> n;

  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      grid[i][j] = 0;
    }
  }

  for( int i = 0; i < n; i++ ){
    cin >> d >> l >> r >> c;
    int c2 = c, r2 = r;

    if( l < 0 || r > 10 ){
      ans = 'N';
      break;
    }

    if(d == 0){
      c += ( l - 1 );

      if(c > 10  || c < 0){
	ans = 'N';
	break;
      }
      for(int j = c2; j <= c; j++){
	if(grid[r-1][j-1] == 1){
	  ans = 'N';
	  break;
	} else{
	  grid[r-1][j-1] = 1;
	}
      }
    } else{
      r += (l - 1);

      if(r > 10 || r < 0){
	ans = 'N';
	break;
      }
      for(int j = r2; j <= r; j++){
	if(grid[j-1][c-1] == 1){
	  ans = 'N';
	  break;
	} else{
	  grid[j-1][c-1] = 1;
	}
      }
    }
  }
  /*for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
    cout<<grid[i][j]<<" ";
    }
    cout<<"\n";
    }*/
  cout << ans << '\n';
  return 0;
}
