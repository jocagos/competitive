#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
constexpr int MAXC = 33;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  bool prev = false;
  string line {}, str {};
  int p {}, counts[MAXC] {};
  while( getline( cin, line ) ){
    if( line == "#" ){ // new case
      for( int i = 0; i < MAXC; ++ i )
	if( counts[i] )
	  cout << i << ' ' << counts[i] << '\n';
      cout << '\n';
      memset( counts, 0, sizeof counts );
    }
    else{
      istringstream iss( line );
      while( iss >> str ){
	int n {};
	if( prev ){
	  prev = false;
	  n += p;
	}
	for( int i = 0; i < (int)str.length(); ++ i )
	  if( ( 'a' <= str[i] and str[i] <= 'z' ) or ( 'A' <= str[i] and str[i] <= 'Z' ) )
	    ++ n;
	if( str.back() == '-' )
	  p = n, prev = true;
	if( not prev )
	  ++ counts[n];
      }
    }
  }
  return 0;
}
