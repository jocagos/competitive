#include <iostream>

using namespace std;

int main(){
  unsigned long long y;
  while( scanf("%llu", &y) == 1 ){
    printf("Y = %llu\n\n", y );
    bool bu = false, leap = false, fest = false;
    if( y % 4 == 0 || (y % 100 != 0 && y % 400 == 0 ) ){ printf("This is leap year.\n"); bu = true; leap = true; }
    if( y % 15 == 0 ){ printf("This is huluculu festival year.\n"); fest = true; }
    if( bu && y % 55 == 0 ){ printf("This is bulukulu festival year.\n"); fest = true; }
    if( !leap && !fest ) printf("This is an ordinary year.\n");
    printf("\n"); 
  }
  return 0;
}
