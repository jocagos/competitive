#include <iostream>
#include <functional>
#include <utility>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
  int n;
  scanf("%d", &n);
  string line;
  getline(cin, line); // Read trailing white space from first line
  getline(cin, line); // Read blank line
  while(n--){
    unordered_map<string, int> species;
    int total = 0;
    while( getline( cin, line ) ){
      if( line[line.length()-1] == '\r' ) line = line.substr(0, line.length()-1);
      if( line == "" or line == "\n" ) break;
      species[line]++;
      total++;
    }
    vector<pair<string, int>> sorted_species;
    for( auto& x : species ) sorted_species.emplace_back(x.first, x.second);
    sort( sorted_species.begin(), sorted_species.end(), [](const pair<string, int>& l, const pair<string, int> r ){ return l.first < r.first; } );
    for( auto& x : sorted_species ){
      cout << x.first << " ";
      printf("%.4f\n", 1.0 * x.second / total * 100 );
    }
    if( n ) cout << endl;
  }
  return 0;
}
