#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void init( unordered_map<string, int>& keys ){
  int idx {1};
  string str = "a";
  for( int i = 'a'; i <= 'z'; ++ i ){
    keys[str] = idx ++;
    ++ str[0];
  }
  str = "ab";
  for( char c1 = 'a'; c1 <= 'y'; ++ c1 ){
    str[0] = c1;
    for( char c2 = c1 + 1; c2 <= 'z'; ++ c2 ){
      str[1] = c2;
      keys[str] = idx ++;
    }
  }
  str = "abc";
  for( char c1 = 'a'; c1 <= 'x'; ++ c1 ){
    str[0] = c1;
    for( char c2 = c1 + 1; c2 <= 'y'; ++ c2 ){
      str[1] = c2;
      for( char c3 = c2 + 1; c3 <= 'z'; ++ c3 ){
	str[2] = c3;
	keys[str] = idx ++;
      }
    }
  }
  str = "abcd";
  for( char c1 = 'a'; c1 <= 'w'; ++ c1 ){
    str[0] = c1;
    for( char c2 = c1 + 1; c2 <= 'x'; ++ c2 ){
      str[1] = c2;
      for( char c3 = c2 + 1; c3 <= 'y'; ++ c3 ){
	str[2] = c3;
	for( char c4 = c3 + 1; c4 <= 'z'; ++ c4 ){
	  str[3] = c4;
	  keys[str] = idx ++;
	}
      }
    }
  }
  str = "abcde";
  for( char c1 = 'a'; c1 <= 'v'; ++ c1 ){
    str[0] = c1;
    for( char c2 = c1 + 1; c2 <= 'w'; ++ c2 ){
      str[1] = c2;
      for( char c3 = c2 + 1; c3 <= 'x'; ++ c3 ){
	str[2] = c3;
	for( char c4 = c3 + 1; c4 <= 'y'; ++ c4 ){
	  str[3] = c4;
	  for( char c5 = c4 + 1; c5 <= 'z'; ++ c5 ){
	    str[4] = c5;
	    keys[str] = idx ++;
	  }
	}
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string str {};
  unordered_map<string, int> keys;
  init( keys );
  while( cin >> str ){
    if( keys.find( str ) == keys.end() )
      cout << "0\n";
    else
      cout << keys[str] << '\n';
  }
  return 0;
}
