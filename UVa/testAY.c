#include <stdio.h>

int main(){
  int i = 0, c = 0;
  FILE * file = fopen("in.txt", "r");
  while( (c = fgetc(file)) != EOF ){
    printf("%c", (char) c);
    i++;
  }
  printf("Counted %d characters\n", i );
  return 0;
}
