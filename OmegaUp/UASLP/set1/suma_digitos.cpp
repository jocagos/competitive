#include <cstdio>

using namespace std;

int main(){
  int c {};
  long long ans {};
  while( (c = getchar()) != EOF ){
    if( '0' <= c and c <= '9' )
      ans += c - '0';
  }
  printf("%lld\n", ans);
  return 0;
}
