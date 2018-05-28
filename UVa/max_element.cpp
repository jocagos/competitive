#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
  srand(time(NULL));
  int grid[10*10];
  for( int i = 0; i < 10; ++ i ){
    for( int j = 0; j < 10; ++ j ){
      cout << (grid[10*i + j] = rand() % (10 * 10)) << (j + 1 == 10 ? "" : " ");
    }
    cout << (i + 1 == 10 ? "\n\n" : "\n");
  }
  cout << *max_element(grid, grid + (10*10)) << endl;
  return 0;
}
