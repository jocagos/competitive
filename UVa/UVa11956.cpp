#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>

using namespace std;

int main(){
  int t, c = 1;
  int m[100];
  char s[1000005];
  scanf("%d ", &t);
  while(t--){
    for( int i = 0; i < 100; ++i ) m[i] = 0;
    scanf("%s", s);
    int j = 0;
    for( int i = 0; s[i]; ++i ){
      if( s[i] == '>' ){
	j++;
	if( j == 100 ) j = 0;
	continue;
      }
      else if( s[i] == '<' ){
	j--;
	if( j == -1 ) j = 99;
	continue;
      }
      else if( s[i] == '+' ){
	m[j]++;
	if( m[j] == 256 ) m[j] = 0;
	continue;
      }
      else if( s[i] == '-' ){
	m[j]--;
	if( m[j] == -1 ) m[j] = 255;
	continue;
      }
    }
    printf("Case %d:", c++);
    for( int i = 0; i < 100; ++i ){
      printf(" %02X", m[i]);
    }
    printf("\n");
  }
  return 0;
}
