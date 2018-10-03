/*
 * UVa 11991 - Easy problem from Rujia Liu?
 * Time limit: 1.000s
 * Time achieved: 0.060s
 * @author: jocagos
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
typedef vector<int> vi;

int main(){
  int n, m;
  while( scanf("%d %d", &n, &m ) != EOF ){
    vi vals(n); // allocate array
    for( int i = 0; i < n; ++i ) scanf("%d", &vals[i] ); // read it
    // since an adjacency list with index as name of the graph would be too big
    // let's hash it with a hashTable (unordered_map)
    unordered_map<int, vector<int>> adjList;
    // Set the adjacencies
    for( int i = 0; i < n; ++i ) adjList[vals[i]].push_back(i);
    int k, v;
    for( int ii = 0; ii < m; ++ii ){
      scanf("%d %d", &k, &v);
      // If the occurence is non-existent, print 0
      if( k > adjList[v].size() ) cout << 0 << endl;
      // Otherwise print the value
      else cout << adjList[v][k-1]+1 << endl;
    }
  }
  return 0;
}
