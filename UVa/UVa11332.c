#include <stdio.h>

int getSum( int );

int main(){
  int f = 0, n = -1;
  scanf("%d", &n);
  while(n){
    do{
      f = getSum(n);
      n = f;
    } while(f >= 10);
    printf("%d\n", f);
    scanf("%d", &n);
  }
  return 0;
}

int getSum( int n )
{
  int f = 0;
  while(n){
    f += n % 10;
    n /= 10;
  }
  return f;
}
