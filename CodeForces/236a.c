#include <stdio.h>
#include <string.h>
int main(){
  char buff[101];
  int bs[256] = {0};
  char c;
  int distinct = 0;
  while( (c = getchar()) != '\n' && c != 13 ){
    bs[c]++;
    if( bs[c] == 1 && c != '\n' ) distinct++;
  }
  c = getchar();
  if( distinct % 2 ) printf("IGNORE HIM!\n");
  else printf("CHAT WITH HER!\n");
  return 0;
}
