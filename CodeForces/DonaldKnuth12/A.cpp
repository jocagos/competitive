#include <iostream>
#include <map>

using namespace std;

int main(){
  string s {};
  cin >> s;
  string t = s;
  for( int i = 0; i < t.length(); ++ i ){
    char & c = t[i];
    if( c == 'o' or c == 'O' )
      c = '0';
    else if( c == 'I' or c == 'i' )
      c = '1';
    else if( c == 'z' or c == 'Z' )
      c = '2';
    else if( c == 'e' or c == 'E' )
      c = '3';
    else if( c == 'a' or c == 'A' )
      c = '4';
    else if( c == 's' or c == 'S' )
      c = '5';
    else if( c == 'g' or c == 'G' )
      c = '6';
    else if( c == 't' or c == 'T' )
      c = '7';
    else if( c == 'B' or c == 'b' )
      c = '8';
  }
  cout << t << endl;
}
