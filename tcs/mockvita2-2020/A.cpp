#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

int main(){
  int TC {};
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> TC;
  unordered_map<char, int> key {};
  while( TC -- ){
    string rules {}, str {};
    cin >> rules;
    for( int i = 0; i < (int)rules.length(); ++ i )
      key[rules[i]] = i;
    cin >> str;
    sort( begin( str ), end( str ), [&key]( char lhs, char rhs ) -> bool {
				      return key[lhs] < key[rhs];
				    });
    cout << str << endl;
  }
  return 0;
}
