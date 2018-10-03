#include <stdio.h>

int main(){
  int c;
  while( (c = getchar()) != EOF ){
    if( c == '\r' || c == '\n' || c == '\v' ) putchar(c);
    else putchar(c-7);
  }
  return 0;
}
