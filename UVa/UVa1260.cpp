#include <iostream>
#include <vector>

using namespace std;

int main(){
  int t;
  scanf("%d", &t);
  while( t-- ){
    int n, count, sum = 0;
    scanf("%d", &n);
    vector<int> sales(n);
    for( int i = 0; i < n; ++ i) scanf("%d", &sales[i]);
    for( int i = 1; i < n; ++ i){
      count = 0;
      for( int j = 0; j < i; ++ j ) if( sales[j] <= sales[i] ) count++;
      sum += count;
    }
    printf("%d\n", sum);
  }
  return 0;
}
