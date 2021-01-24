#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string line {};
  while( line != "****END_OF_INPUT****" ){
    while( getline( cin, line ) ){
      if( line == "****END_OF_TEXT****" )
	break;
    }
  }
  return 0;
}
