#include <iostream>
#include <list>
// This version uses std::string constructor to handle the growth
// It gives TLE!
using namespace std;

int main(){
  string line;
  string ans {};
  while( getline(cin, line) ){
    if( line[line.length()-1] == '\r' ) line = line.substr(0, line.length()-1);
    int pos = 0;
    string s {};
    /*    list<string> l;*/
    for( int i = 0; i < line.length(); ++i ){
      if( line[i] != '[' and line[i] != ']' ) s += line[i];
      else if( line[i] == '[' ){
	if( pos <= 0 ) ans = s + ans, s.clear();/*l.push_front(s), s.clear();*/
	else ans = ans + s, s.clear();/*l.push_back(s), s.clear();*/
	pos = -1;
      }
      else{
	if( pos <= 0 ) ans = s + ans, s.clear();/*l.push_front(s), s.clear();*/
	else ans = ans + s, s.clear();/*l.push_back(s), s.clear();*/
	pos = 1;
      }
    }
    if(!s.empty()){
      if( pos <= 0 ) ans = s + ans, s.clear();/*l.push_front(s), s.clear();*/
      else ans = ans + s, s.clear();/*l.push_back(s), s.clear();*/
    }
    /*    for( auto& it : l ) cout << it;*/
    cout << ans;
    cout << endl;
    ans.clear();
  }
  return 0;
}
