#include <bits/stdc++.h>

using namespace std;

int main(){
  int c {}, idx {};
  char buf[1025];
  while( (c = getchar()) != EOF ){
    if( isspace( c ) ){
      idx --;
      while( idx >= 0 and buf[idx] )
	putc( buf[idx --], stdout );
      buf[0] = idx = 0;
      putc( c, stdout );
    }
    else{
      buf[idx ++] = c;
    }
  }
  return 0;
}
