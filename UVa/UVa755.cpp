#include <iostream>
#include <string>
#include <map>

using namespace std;
constexpr int MAXC = 256;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string str {};
  int tc {}, n {};
  cin >> tc;
  int vals[MAXC] {};
  char ans[10] {};
  vals['0'] = '0';
  vals['1'] = '1';
  vals['A'] = vals['B'] = vals['C'] = vals['2'] = '2';
  vals['D'] = vals['E'] = vals['F'] = vals['3'] = '3';
  vals['G'] = vals['H'] = vals['I'] = vals['4'] = '4';
  vals['J'] = vals['K'] = vals['L'] = vals['5'] = '5';
  vals['M'] = vals['N'] = vals['O'] = vals['6'] = '6';
  vals['P'] = vals['R'] = vals['S'] = vals['7'] = '7';
  vals['T'] = vals['U'] = vals['V'] = vals['8'] = '8';
  vals['W'] = vals['X'] = vals['Y'] = vals['9'] = '9';
  while( tc -- ){
    cin >> n;
    map<string, int> keys;
    int i {}, j {};
    while( n -- ){
      cin >> str;
      for( i = 0; i < str.length(); ++ i ){
	if( j == 3 )
	  ans[j ++] = '-';
	if( ('A' <= str[i] and str[i] <= 'Z') or ('0' <= str[i] and str[i] <= '9') )
	  ans[j ++] = vals[str[i]];
      }
      ans[j] = '\0';
      j = 0;
      keys[ans] ++;
    }
    int dupes {};
    for( auto& it : keys ){
      if( it.second > 1 ){
	++ dupes;
	cout << it.first << " " << it.second << '\n';
      }
    }
    if( dupes == 0 )
      cout << "No duplicates.\n";
    if( tc )
      cout << '\n';
  }
  return 0;
}
