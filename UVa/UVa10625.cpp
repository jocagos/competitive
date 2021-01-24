#include <iostream>
#include <string>

using namespace std;
constexpr int MAXC = 256;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  string str {}
  int counts[MAXC][MAXC] {};
  string keys[MAXC] {};
  cin >> tc;
  while( tc -- ){
    int n {}, q {};
    cin >> n;
    for( int i = 0; i < n; ++ i ){
      cin >> str;
      keys[str[0]] = str.substr( 3 );
      for( int j = 0; j < (int)keys[str[0]].length(); ++ j )
	++ counts[str[0]][keys[str[0]][j]];
    }
  }
  return 0;
}
