#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main(){
  int tc {};
  cin >> tc;
  for( int CASE = 1; CASE <= tc; ++ CASE ){
    string input {};
    cin >> input;
    int depth = 0;
    string ans {};
    int i = 0;
    while( i < input.length() ){
      int lvl = input[i] - '0';
      if( depth < lvl ){
	while( depth < lvl ){
	  ans += '(';
	  depth ++;
	}
      }
      else if( lvl < depth ){
	while( lvl < depth ){
	  ans += ')';
	  depth --;
	}
      }
      ans += input[i];
      ++ i;
    }
    while( depth -- ){
      ans += ')';
    }
    cout << "Case #" << CASE << ": " << ans << endl;
  }
  return 0;
}
