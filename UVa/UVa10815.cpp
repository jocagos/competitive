#include <iostream>
#include <string>
#include <set>

using namespace std;
constexpr int MAXC = 255;
char to_lower[MAXC] {};

void init(){
  for( int i = 'A'; i <= 'Z'; ++ i )
    to_lower[i] = 'a' + (i - 'A');
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  init();
  string line {};
  set<string> dict;
  while( getline( cin, line ) ){
    // to lower processing
    for( int i = 0; i < (int)line.length(); ++ i )
      if( 'A' <= line[i] and line[i] <= 'Z' )
	line[i] = to_lower[line[i]];
    // now just match the words
    int L {}, R {};
    bool match {};
    while( L < (int)line.length() ){
      while( match ){
	if( R < (int)line.length() and
	    (('a' <= line[R] and line[R] <= 'z') or
	     ('A' <= line[R] and line[R] <= 'Z')) )
	  ++ R;
	else{
	  match = false;
	  string tmp = line.substr( L, R - L );
	  if( tmp.length() )
	    dict.emplace( tmp );
	  L = R;
	}
      }
      if( ('a' <= line[L] and line[L] <= 'z') or
	  ('A' <= line[L] and line[L] <= 'Z') ){
	match = true;
	R = L + 1;
      }
      else
	++ L;
    }
  }
  for( auto& str : dict )
    cout << str << '\n';
  return 0;
}
