#include <iostream>
#include <vector>
#include <string>

using namespace std;
constexpr int MAXW = 1010, MAXC = 27;
int words[MAXW][MAXC] {};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int idx {};
  string line {};
  while( getline( cin, line ), line != "#" ){
    for( int i = 0; i < (int)line.length(); ++ i )
      ++ words[idx][line[i] - 'a'];
    ++ idx;
  }
  while( getline( cin, line ), line != "#"){
    int letters[MAXC] {};
    for( int i = 0; i < (int)line.length(); ++ i )
      if( 'a' <= line[i] and line[i] <= 'z' )
	++ letters[line[i] - 'a'];
    bool valid = true;
    int cnt {};
    for( int i = 0; i < idx; ++ i ){
      valid = true;
      for( int j = 0; j < MAXC and valid; ++ j )
	valid = (valid and (words[i][j] <= letters[j]));
      cnt += valid;
    }
    cout << cnt << '\n';
  }
  return 0;
}
