#include <stdio.h>
#include <stdlib.h>

int main(){
  char c;
  int s = 0, score = 0, prev = 0, try = 0;
  while( (c = getchar()) != EOF ){
    if( s < 0 ) s = 0;
    if( c == ' ' ) continue; /* whitespace, skip */
    else if( c == 'X' ){ /* Strike, set s to two for next two shots */
      if( s && try < 20 ) score += 10, s--; /* if prev was a strike, and this one too, sum 10, set s */
      s += 2;
      score += 10;
      try += 2;
    }
    else if( c == '/' ){ /* Spare, set s to one for next shot */
      if( s && try < 20 ) score += 10 - prev, s--; /* we sum the difference so we never 're-add' */
      s += 1;
      score += 10 - prev;
      try++;
    }
    else if( c >= '0' && c <= '9' ){ /* numerical value, just sum it */
      if( s && try < 20 ) score += c - '0', s--;
      score += c - '0';
      prev = c - '0'; /* set prev in case we need it later for a spare */
      try++;
    }
    else if( c == '\n' ){
      printf("%d\n", score);
      score = 0; /* reset score, shots, prev */
      prev = 0;
      s = 0;
      try = 0;
    }
    else if( c == 'G' ) break;
  }
  return 0;
}
