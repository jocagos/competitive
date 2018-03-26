#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>

using namespace std;

int main(){
  int t, c = 1;
  int m[100];
  scanf("%d ", &t);
  while(t--){
    for( int i = 0; i < 100; ++i ) m[i] = 0;
    string s;
    cin >> s;
    int j = 0;
    for( int i = 0; i < s.length(); ++i ){
      if( s[i] == '>' ) j = (j+1)%100;
      else if( s[i] == '<' ) j = (j-1 < 0 ? 99 : j-1);
      else if( s[i] == '+' ) m[j] = (m[j]+1)%256;
      else if( s[i] == '-' ) m[j] = (m[j]-1 < 0 ? 255 : m[j]-1);
    }
    printf("Case %d: ", c++);
    char tmp[20];
    for( int i = 0; i < 100; ++i ){
      sprintf(tmp, "%02x%s", m[i],(i+1 == 100 ? "\n" : " "));
      for( int k = 0; k < strlen(tmp); ++k ) putchar(toupper(tmp[k]));
    }
  }
  return 0;
}
