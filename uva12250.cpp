#include <stdio.h>
#include <iostream>
#include <string>

#define optimize_ios() ios_base::sync_with_stdio(0);cin.tie(0)

using namespace std;


int main(){
  string s;
  optimize_ios();
  int i = 1;
  do{
    cin >> s;
    if( s == "#" )
      break;
    cout << "Case " << i++ << ": ";
    if( s == "HOLA" )
      cout << "SPANISH" << endl;
    else if( s == "HELLO" )
      cout << "ENGLISH" << endl;
    else if( s == "CIAO" )
      cout << "ITALIAN" << endl;
    else if( s == "HALLO" )
      cout << "GERMAN" << endl;
    else if( s == "BONJOUR" )
      cout << "FRENCH" << endl;
    else if( s == "ZDRAVSTVUJTE" )
      cout << "RUSSIAN" << endl;
    else
      cout << "UNKNOWN" << endl;
  }while( true );
  return 0;
}
