#include <iostream>
#include <cstring>
#define abs(x) ((x) > 0 ? (x) : (-(x)))
using namespace std;

int main(){
  int n, num[3000];
  bool ans, checked[10000];
  memset(num, 0, sizeof num);
  while( scanf("%d", &n) != EOF ){
    memset(checked, 0, sizeof checked);
    ans = true;
    for( int i = 0; i < n; ++i ) scanf("%d", &num[i]); // store sequence
    for( int i = 1; i < n; ++i ) checked[3000+abs(num[i]-num[i-1])] = true; // store if a difference has been seen or not
    for( int i = 1; i < n; ++i ) if( ans ) ans &= checked[3000+i]; else break;
    if( ans ) printf("Jolly\n");
    else printf("Not jolly\n");
  }
  return 0;
}
