#include <iostream>
#include <functional>
#include <utility>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cstdio>

using namespace std;

int main(){
  int n;
  scanf("%d", &n);
  string line;
  getline(cin, line); // Read trailing white space from first line
  getline(cin, line); // Read blank line
  auto f = []( const pair<string, int>& a, const pair<string, int>& b ){ return a.first < b.first; };
  while(n--){
    unordered_map<string, int> species;
    int total = 0;
    while( getline( cin, line ) ){
      //if( line[line.length()-1] == '\r' ) line = line.substr(0, line.length()-1);
      if( line == "" or line == "\n" ) break;
      species[line]++;
      total++;
    }
    vector<string> sorted_species(species.size());
    for( auto x : species ) sorted_species.emplace_back(x.first);
    sort( sorted_species.begin(), sorted_species.end() );
    for( auto& x : sorted_species ){
      cout << x << " ";
      printf("%.4f\n", 1.0 * species[x] / total * 100 );
    }
    if( n ) cout << endl;
  }
  return 0;
}
