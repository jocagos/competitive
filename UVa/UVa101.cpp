#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

static inline void rtrim(string &s) {
    s.erase(find_if(s.rbegin(), s.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), s.end());
}

int main(){
  int n;
  scanf("%d", &n);
  string line("");
  vector<int> base(n);
  vector<vector<int>> blocks(n, base);
  while( line != "quit" ){
    if( line == "" ){
      getline(cin, line);
      rtrim( line );
      continue;
    }
    getline(cin, line);
    rtrim( line );
    if( line == "quit" ) break;
    istringstream iss(line);
    string action, _type;
    int a, b;
    iss >> action >> a >> _type >> b;
    if( a == b ) continue;
    
  }
  return 0;
}
