#include <cstdio>

using namespace std;

int main(){
  for(int i = 0; i < 3; ++i )
    if( i == 1 ) printf("call me maybe?\n");
    else if( i == 2 ) printf("or not?\n");
    else printf("Better Call Saul!\n");
  return 0;
}
