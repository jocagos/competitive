#include <iostream>

using namespace std;

int dt2dy( int d, int m, int y ){
  return ( y / 400 + (y % 400) / 4 - 3 + /* years to days taking into account leap years */
	   ( y % 400 == 0 || (y % 4 == 0 && y % 100 != 0) ? sumonths[m] - months[m] + d : sumonths[m] - months[m] + d + 1 )
}

int main(){
  int d, m, y;
  long n;
  int months[12] { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  int sumonths[12] { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
  while( scanf("%ld %d %d %d ", &n, &d, &m, &y), l || d || m || y ){
    
  }
  return 0;
}
