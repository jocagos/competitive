#include <iostream>

using namespace std;

int main(){
  long long n;
  while( scanf("%lld", &n) != EOF ){
    long long hmil = n % 10000 * 10 + (n / 10000 % 100) * 60000 + (n / 1000000 * 3600000 );
    printf("%lld%02lld%02lld%02lld\n", hmil/8640000L, hmil/86400L % 100, hmil/864L % 100, hmil*100/864 % 100);
  }
  return 0;
}
