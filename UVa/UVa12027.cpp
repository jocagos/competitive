#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  while( cin >> s ){
    if( s == "0" or s == "0\r" or s == "0\n" or s == "0\n\r" )
      break;
    int l = s.length();
    int first = s[0] - '0';
    if( l > 1 and l % 2 == 0 ) first = first * 10 + s[1] - '0';
    l = (l-1)/2;
    string zeroes(l, '0');
    cout << static_cast<int>(sqrt(first)) << zeroes << endl;
  }
  return 0;
}
