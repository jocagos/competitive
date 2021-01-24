#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  string str {};
  while( cin >> n >> str ){
    int delta = str.length() - n;
    unordered_map<string, int> keys;
    for( int i = 0; i <= delta; ++ i ){
      string s = str.substr(i, n);
      keys[s] ++;
    }
    int mx {};
    for( auto& it : keys ){
      if( it.second > mx ){
	str = it.first;
	mx = it.second;
      }
    }
    cout << str << '\n';
  }
  return 0;
}
