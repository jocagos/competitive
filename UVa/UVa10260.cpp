#include <iostream>
#include <string>

using namespace std;
constexpr int MAXC = 256;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string str {};
  int digits[MAXC] {};
  digits['A'] = digits['E'] = digits['I'] = digits['O'] = digits['U'] = digits['H'] = digits['W'] = digits['Y'] = -1;
  digits['B'] = digits['F'] = digits['P'] = digits['V'] = 1;
  digits['C'] = digits['G'] = digits['J'] = digits['K'] = digits['Q'] = digits['S'] = digits['X'] = digits['Z'] = 2;
  digits['D'] = digits['T'] = 3;
  digits['L'] = 4;
  digits['M'] = digits['N'] = 5;
  digits['R'] = 6;
  while( cin >> str ){
    for( int i = 0; i < (int)str.length(); ++ i )
      if( digits[str[i]] > 0 ){
	if( i > 0 and digits[str[i - 1]] != digits[str[i]] )
	  cout << digits[str[i]];
	else if( i == 0 )
	  cout << digits[str[i]];
      }
    cout << '\n';
  }
  return 0;
}
