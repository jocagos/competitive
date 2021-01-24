#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
constexpr int MAX_FILES = 150;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string line {};
  string parts[MAX_FILES] {};
  getline( cin, line );
  int tc = stoi( line );
  getline( cin, line ); // blank
  while( tc -- ){
    unordered_map<string, int> files;
    int idx {};
    // read until blank
    while( getline( cin, parts[idx] ), parts[idx] != "" )
      ++ idx;
    // concatenate all strings, make the keys
    for( int i = 0; i < idx; ++ i ){
      for( int j = 0; j < idx; ++ j ){
	if( i == j ) continue;
	files[parts[i] + parts[j]] ++;
      }
    }
    // get max
    int mx {};
    for( auto& it : files )
      if( it.second > mx )
	mx = it.second;
    for( auto& it : files )
      if( it.second == mx ){
	cout << it.first << '\n';
	break;
      }
    if( tc ) cout << '\n';
  }
  return 0;
}
