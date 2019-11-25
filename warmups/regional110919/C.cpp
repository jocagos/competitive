#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string line {};
  int n {};
  getline( cin, line );
  n = stoi( line );
  set<string> str;
  while( n -- ){
    getline( cin, line );
    int at = line.find( '@' );
    auto _left = line.substr( 0, at );
    int plus = _left.find( '+' );
    _left = _left.substr( 0, plus );
    auto right = line.substr( at );
    string s = _left;
    unsigned i {}, j {};
    for( i = 0, j = 0; i < _left.length() and j < s.length(); ++ i, ++ j ){
      if( _left[j] != '.' )
	s[i] = _left[j];
      else
	i --;
    }
    s = s.substr( 0, min( i, j ) ) + right;
    // cerr << "left: " << _left << "\ns: " << s << right << endl;
    str.emplace( s );
  }
  cout << str.size() << endl;
  return 0;
}
