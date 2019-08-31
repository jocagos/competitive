#include <iostream>
#include <string>

using namespace std;

int main( void ){
  string s;
  cin >> s;
  for( int i = 0; i < s.length(); ++ i ) s[i] = 1 - (s[i] - '0') + '0';
  cout << s << '\n';
  return 0;
}
