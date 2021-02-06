#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>
#include <cmath>
#include <bitset>

using namespace std;
constexpr int MAXP = 10010 * 16;
constexpr int MAX_BITS = 128;
// We could avoid using bitset if we used an array of ULLs
// but manipulating it correctly takes time, which is precious
// in Competitive Programming!
bitset<MAX_BITS> masks[MAXP] {};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  string line {};
  getline( cin, line );
  tc = stoi( line );
  getline( cin, line ); // blank
  while( tc -- ){
    getline( cin, line ); // data
    int p {}, t {}, person {}, tree {};
    istringstream base_in( line );
    base_in >> p >> t;
    for( int i = 0; i < p; ++ i )
      masks[i].reset();
    while( getline( cin, line ) ){
      if( line == "" ) break;
      istringstream iss( line );
      iss >> person >> tree;
      -- person;
      -- tree;
      masks[person][tree] = 1;
    }
    if( t > sizeof( unsigned long long ) ){
      unordered_set<string> diffs;
      for( int i = 0; i < p; ++ i )
	diffs.emplace( masks[i].to_string() );
      cout << diffs.size() << '\n';
    }
    else{
      unordered_set<unsigned long long> diffs;
      for( int i = 0; i < p; ++ i )
	diffs.emplace( masks[i].to_ullong() );
      cout << diffs.size() << '\n';
    }
    if( tc ) cout << '\n';
  }
  return 0;
}
