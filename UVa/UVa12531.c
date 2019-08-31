#include <stdio.h>

int main(){
  int n;
  while( scanf("%d", &n) != EOF )
    printf("%s", (n % 6 == 0 ? "Y\n" : "N\n" ) );
  return 0;
}
