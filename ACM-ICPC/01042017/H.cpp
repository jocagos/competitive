#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <cmath>
#define MAX 1000000000000

using namespace std;

int main(){
  int t;
  scanf("%d", &t);
  map<int, int> odd, even, squares;
  for( long i = 1, o = 0, e = 1; i <= sqrt(MAX); ++i ){
    if( i % 2 ) odd[o++] = i * i;
    else even[e++] = i * i;
    squares[i] = i * i;
  }
  while(t--){
    int n;
    scanf("%d", &n);
    if( n 
    printf("%d %d",  );
  }
  return 0;
}
