#include <bits/stdc++.h>

using namespace std;

unordered_map<char, char> to;
string FROM = R"***(`1234567890-=qwertyuiop[]\asdfghjkl;'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:"ZXCVBNM<>?)***",
         TO = R"***(`123qjlmfp/[]456.orsuyb;=\789aehtdck-0zx,inwvg'~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG")***";

void init(){
  for( unsigned i = 0; i < FROM.length(); ++ i )
    to[FROM[i]] = TO[i];
}

int main(){
  init();
  int c;
  while( (c = getchar()) != EOF ){
    if( c == '\n' or c == ' ' or c == '\t' )
      putchar( c );
    else
      putchar( to[c] );
  }
  return 0;
}
