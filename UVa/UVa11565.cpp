#include <iostream>

using namespace std;

int main(){
  int t;
  scanf("%d", &t);
  int a, b, c;
  bool sol = false;
  while( t-- ){
    scanf("%d %d %d", &a, &b, &c);
    sol = false;
    int x, y, z;
    for( x = -25; x <= 25 and !sol; ++ x ){
      if( x * x <= c ){
	for( y = -100; y <= 100 and !sol; ++ y ){
	  if( y != x and x * x + y * y <= c ){
	    for( z = -100; z <= 100 and !sol; ++ z ){
	      if( z != x and z != y and x + y + z == a and x * y * z == b and x *x + y * y + z * z == c ) printf("%d %d %d\n", x, y, z), sol = true;
	    }
	  }
	}
      }
    }
    if( !sol ) printf("No solution.\n");
  }
  return 0;
}
