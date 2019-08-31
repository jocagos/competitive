#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

bool isr( char c ){ return c == '\r'; };

int main(){
  string line;
  int n;
  scanf("%d", &n);
  getline( cin, line );
  getline( cin, line );
  while( n -- ){
    vector<string> lines;
    line = ".";
    // Process input and save it
    while( line != "" and line != "\n" and line != "\n\r" and line != "\r" ){
      getline( cin, line );
      line.erase( remove_if( line.begin(), line.end(), isr ), line.end());
      lines.push_back( line );
    }
    sort(lines.begin(), lines.end());
    // Create output
    set<pair<string, string>> anagrams;
    for( int i = 0; i < lines.size(); ++ i ){
      for( int j = 0; j < lines.size(); ++ j ){
	if( i == j ) continue;
	string s(lines[i]), t(lines[j]);
	s.erase( remove_if( s.begin(), s.end(), ::isspace ), s.end() );
	t.erase(remove_if( t.begin(), t.end(), ::isspace ), t.end() );
	sort(s.begin(), s.end()); sort(t.begin(), t.end());
	if( s == t ){
	  pair<string, string> p;
	  if( lines[i] < lines[j] ) p.first = lines[i], p.second = lines[j];
	  else p.first = lines[j], p.second = lines[i];
	  anagrams.insert( p );
	}
      }
    }
    for( auto& x : anagrams )  cout << x.first << " = " << x.second << "\n";
    if( n ) cout << endl;
  }
  return 0;
}
