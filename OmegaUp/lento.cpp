#include <cstdio>

using namespace std;
constexpr int MAXN = 1000100;
int vals[MAXN] {};

int main(){
  int n {}, mn_odd {MAXN};
  long long sum {};
  scanf("%d", &n);
  for( int i = 0; i < n; ++ i ){
    scanf("%d", &vals[i]);
    sum += vals[i];
    if( (vals[i] & 1) and vals[i] < mn_odd )
      mn_odd = vals[i];
  }
  if( sum & 1LL ){ // sum is odd already
    printf("%lld\n", sum);
  }
  else{
    if( mn_odd == MAXN )
      printf("0\n");
    else
      printf("%lld\n", sum - mn_odd);
  }
  return 0;
}
