#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main(){
  int n;
  scanf("%d", &n);
  while(n--){
    int p, q;
    string line;
    scanf("%d ", &p);
    vvi neighbours(p+1); //AdjList to store connectivity of the neighbours
    vi best_places; // dummy vector to store places with minimized size of AdjList
    for( int i = 1; i <= p; ++i ){
      int tmp;
      getline(cin, line); // read line
      istringstream iss(line); // Process it with a stream
      // read whole stream and store the connections in AdjList
      while( iss >> tmp ) neighbours[i].push_back(tmp);
    }
    int minSize = 1001, minSizeIdx = -1; // Initialization for mins
    for( int i = 1; i <= p; ++i ){ // Avoid index zero and find minSize
      if( neighbours[i].size() < minSize ) minSize = neighbours[i].size(), minSizeIdx = i;
    }
    for( int i = 1; i <= p; ++i ){ // Push all with minSize to best_places
      if( neighbours[i].size() == minSize ) best_places.push_back(i);
    }
    for( int i = 0; i < best_places.size(); ++i ) cout << best_places[i] << (i+1 == best_places.size() ? "\n" : " " ); // loop through best_places
    if( n ) getline(cin, line); // read blank line before next case if any
  }
  return 0;
}
