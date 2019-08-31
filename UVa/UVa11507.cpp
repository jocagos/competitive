#include <iostream>

using namespace std;

int main(){
  int x, y, z, t; string s, ans; bool first = false;
  while( scanf("%d", &t), t != 0){
    ans = "+x";
    for( int i = 1; i < t; ++i ){
      cin >> s;
      if( s == "No" ) continue;
      if( s == "+y" ){
	if( ans == "+x" ) ans = "+y";
	else if( ans == "-x" ) ans = "-y";
	else if( ans == "+y" ) ans = "-x";
	else if( ans == "-y" ) ans = "+x";
      }
      else if( s == "-y" ){
	if( ans == "+x" ) ans = "-y";
	else if( ans == "-x" ) ans = "+y";
	else if( ans == "+y" ) ans = "+x";
	else if( ans == "-y" ) ans = "-x";
      }
      else if( s == "+z" ){
	if( ans == "+x" ) ans = "+z";
	else if( ans == "-x" ) ans = "-z";
	else if( ans == "+z" ) ans = "-x";
	else if( ans == "-z" ) ans = "+x";
      }
      else if( s == "-z" ){
	if( ans == "+x" ) ans = "-z";
	else if( ans == "-x" ) ans = "+z";
	else if( ans == "+z" ) ans = "+x";
	else if( ans == "-z" ) ans = "-x";
      }
    }
    cout << ans << endl;
  }
  return 0;
}
