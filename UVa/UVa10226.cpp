#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  string line {};
  getline( cin, line );
  n = stoi( line );
  getline( cin, line ); // blank
  while( n -- ){
    map<string, int> species;
    int total = 0;
    while( getline( cin, line ) ){
      if( line == "" ) break;
      ++ species[line];
      ++ total;
    }
    for( auto& x : species )
      cout << x.first << " " << setprecision( 4 ) << fixed
	   << 100.0 * x.second / total << '\n';
    if( n ) cout << endl;
  }
  return 0;
}
