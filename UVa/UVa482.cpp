#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
constexpr int MAXN = 1000010; // 1m + 10

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string line {};
  getline( cin, line );
  int tc = stoi( line );
  // many ways to do it:
  // 1. use a map
  // 2. use a vector and sort it with lambda
  // 3. use a vector with n + 1 items, assign directly
  for( int i = 0; i < tc; ++ i ){
    getline( cin, line ); // skip the empty line
    getline( cin, line );
    istringstream iss(line);
    string second;
    getline( cin, second );
    istringstream iss_2(second);
    int key {};
    string val {};
    map<int, string> vals;
    while( iss >> key ){
      getline( iss_2, val, ' ' );
      vals[key] = val;
    }
    for( auto it = vals.begin(); it != vals.end(); ++ it )
      cout << it->second << '\n';
    if( i + 1 < tc )
    cout << '\n';
  }
  return 0;
}
