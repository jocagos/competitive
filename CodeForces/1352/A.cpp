#include <iostream>
#include <string>
#include <cstdlib>
#include <set>

using namespace std;

void partition_number( std::string num ){
  set<string> vals;
  for( int i = 0; i < num.length(); ++ i ){
    if( num[i] != '0' ){
      string s( num.length() - i, '0' );
      s[0] = num[i];
      vals.emplace( s );
    }
  }
  cout << vals.size() << '\n';
  int i = 0;
  for( auto it = vals.begin(); it != vals.end(); ++ it, ++ i ){
    cout << *it << ( i + 1 == vals.size() ? "\n" : " ");
  }
}
  
int main(){
  string line {};
  int n {};
  getline( cin, line );
  n = stoi( line );
  for( int i = 0; i < n; ++ i ){
    getline( cin, line );
    partition_number( line );
  }
  return 0;
}
