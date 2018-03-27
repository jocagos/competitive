#include <stdio.h>
#include <stdlib.h>

int main(){
  long long int t, f, a, an, deg, sum;
  scanf("%lld", &t);
  while(t--){
    scanf("%lld", &f);
    sum = 0;
    while(f--){
      scanf("%lld %lld %lld", &a, &an, &deg);
      sum += a * deg;
    }
    printf("%lld\n", sum);
  }
  return 0;
}
