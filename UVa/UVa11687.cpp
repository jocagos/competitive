#include <iostream>
#include <string>

using namespace std;

int main(){
  string s;
  while( cin >> s, s != "END" ){
    int i = 0, j = 0, c = 1;
    i = to_string(s.length()).length();
    if( s == "1" ){ cout << c << endl; continue;}
    else if( s.length() == 1 ){ cout << "2" << endl; continue;}
    while( i != j ){
      j = i;
      i = to_string(j).length();
      c++;
    }
    cout << c+1 << endl;
  }
  return 0;
}
