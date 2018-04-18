#include <iostream>
#include <list>
// Possible speed-up by keeping indexes of the string then using substr to push in the list
// It sounds better than keeping a string and summing every time since it can be expensive
using namespace std;

int main(){
  string line;
  while( getline(cin, line) ){
    if( line[line.length()-1] == '\r' ) line = line.substr(0, line.length()-1);
    int pos = 0;
    string s {};
    list<string> l;
    for( int i = 0; i < line.length(); ++i ){
      if( line[i] != '[' and line[i] != ']' ) s += line[i];
      else if( line[i] == '[' ){
	if( pos <= 0 ) l.push_front(s), s.clear();
	else l.push_back(s), s.clear();
	pos = -1;
      }
      else{
	if( pos <= 0 ) l.push_front(s), s.clear();
	else l.push_back(s), s.clear();
	pos = 1;
      }
    }
    if(!s.empty()){
      if( pos <= 0 ) l.push_front(s), s.clear();
      else l.push_back(s), s.clear();
    }
    for( auto& it : l ) cout << it;
    cout << endl;
  }
  return 0;
}
