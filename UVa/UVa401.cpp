#include <iostream>
#include <map>

using namespace std;

int main(){
  map<char, char> mirror { {'A', 'A'}, {'E', '3'}, {'H', 'H'}, {'I', 'I'}, {'J', 'L'}, {'L', 'J'}, {'M', 'M'}, {'O', 'O'}, {'S', '2'}, {'T', 'T'}, {'U', 'U'}, {'V', 'V'}, {'W', 'W'}, {'X', 'X'}, {'Y', 'Y'}, {'Z', '5'}, {'1', '1'}, {'2', 'S'}, {'3', 'E'}, {'5', 'Z'}, {'8', '8'} };
  string line;
  while( getline(cin, line) ){
    if( *line.rbegin() == '\r' ) line.erase(line.length()-1, 1);
    bool m = true, p = true;
    if( line.length() == 1 ){
      if( mirror[line[0]] == line[0] ) cout << line << " -- is a mirrored palindrome." << endl << endl;
      else cout << line << " -- is a regular palindrome." << endl << endl;
      continue;
    }
    for( int i = 0, j = line.length()-1; i <= line.length() / 2 && (m || p); ++i, --j ){
      if( line[i] != line[j] ) p = false;
      if( line[i] != mirror[line[j]] ) m = false;
    }
    if( m && p ) cout << line << " -- is a mirrored palindrome." << endl;
    else if( m ) cout << line << " -- is a mirrored string." << endl;
    else if( p ) cout << line << " -- is a regular palindrome." << endl;
    else cout << line << " -- is not a palindrome." << endl;
    cout << endl;
  }
  return 0;
}
