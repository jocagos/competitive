#include <cstdio>

using namespace std;

int main(){
  int t, s = 0, tmp;
  double sum;
  int nums[200000];
  scanf("%d", &t);
  for( int i = 0; i < t; ++i ){
    scanf("%d", &tmp);
    s += tmp;
    nums[i] = s;
  }
  sum = s;
  for( int i = 0; i < t; ++i ){
    if( nums[i] >= sum / 2.0 ){
      printf("%d\n", i+1);
      break;
    }
  }
  return 0;
}
