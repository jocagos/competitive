#include <iostream>
#include <cstring>

using namespace std;

int main(){
  int n;
  scanf("%d ", &n);
  while(n--){
    /* Jagged array */
    int * grid[5];
    for( int i = 0; i < 5; ++i ) grid[i] = (i == 2 ? new int[4] : new int[5]);
    
  }
  return 0;
}
