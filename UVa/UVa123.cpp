#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

int main(){
  string s;
  while( s != "::" ){
    getline( cin, s );
    if( s[s.length()-1] == '\r' ) s = s.substr(0, s.length()-1);
    if( s == "::" ) break;
    
  }
  return 0;
}
