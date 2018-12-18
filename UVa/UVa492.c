#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char s[1000001];
char * t;
char prev = '\0';

int main(){
  int idx = 0, c = 0, first = 0;
  while( (c = getchar()) != EOF ){
    if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ){
      if( idx == 0 ) first = c;
      s[idx++] = c;
    }
    else{
      if( !(first == 'a' || first == 'A' || first == 'e' || first == 'E' || first == 'i' || first == 'I' || first == 'o' || first == 'O' || first == 'u' || first == 'U' ) && idx ){
	s[idx++] = first;
	t = s + 1;
      }
      else t = s;
      if( idx ){
	s[idx++] = 'a';
	s[idx++] = 'y';
	s[idx] = '\0';
	printf("%s", t);
      }
      idx = 0;
      putchar( c );
    }
  }
  /* printf("\n"); */
  return 0;
}
