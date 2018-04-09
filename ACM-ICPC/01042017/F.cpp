#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    long long s;
    scanf("%lld", &s);
    printf("%lld\n", s * (s + 2));
  }
  return 0;
}
