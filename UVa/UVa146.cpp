#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  string line;
  getline(cin, line);
  while( line != "#" ){
    if( line[line.length()-1] == '\r' ) line = line.substr(0, line.length()-1);
    if( next_permutation(line.begin(), line.end())) cout << line << endl;
    else cout << "No Successor" << endl;
    getline(cin, line);
  }
}
