#include <iostream>
#include <vector>
#include <string>

using namespace std;

int cmp( string& lhs, string& rhs ){
  if( lhs.length() != rhs.length() ){
    return ((int)lhs.length()) - ((int)rhs.length());
  }
  int idx {};
  while( lhs[idx] == rhs[idx] ) ++ idx;
  if( idx == (int) lhs.length() ) return 0;
  else return ((int)lhs[idx]) - ((int)rhs[idx]);
}

string max_str( vector<string>& strings ){
  string maxx = strings[0];
  for( int i = 1; i < (int)strings.size(); ++ i ){
    if( cmp( maxx, strings[i] ) < 0 ){
      maxx = strings[i];
    }
  }
  return maxx;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s {};
  int digits[10] {};
  cin >> s;
  for( int i = 1; i < 10; ++ i )
    cin >> digits[i];
  for( int d = 1; d <= 9; ++ d ){
    if( digits[d] == 0 ) continue;
    while( digits[d] -- ){
      vector<string> choices;
      for( int i = 0; i < (int)s.length(); ++ i ){
	if( s[i] == '0' + d )
	  choices.emplace_back( s.substr( 0, i ) + s.substr( i + 1 ) );
      }
      s = max_str( choices );
    }
  }
  cout << s << '\n';
  return 0;
}
