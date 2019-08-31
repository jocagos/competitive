#include <iostream>
#include <vector>
#include <bitset>
#include <cstring>

using namespace std;

typedef vector<int> vi;

int main(){
  int n;
  while( scanf("%d", &n) != EOF ){
    int m;
    scanf("%d ", &m);
    string line;
    if( m == 0 ){
      cout << "THIS BRAIN NEVER WAKES UP" << endl;
      getline(cin, line);
      continue;
    }
    getline( cin, line );
    vector<vector<int>> adjList(26);
    bitset<26> awaken(0UL);
    awaken.set(line[0]-'A', 1);
    awaken.set(line[1]-'A', 1);
    awaken.set(line[2]-'A', 1);
    // Build adjList
    for( int i = 0; i < m; ++i ){
      getline( cin, line );
      adjList[line[0]-'A'].emplace_back((int)(line[1]-'A'));
      adjList[line[1]-'A'].emplace_back((int)(line[0]-'A'));
    }
    int years = 0;
    while( !awaken.all() ){
      vector<int> to_awake;
      for( int i = 0; i < 26; ++i )
	if( adjList[i].size() >= 3 ) to_awake.push_back(i);
      for( auto& x : to_awake )	awaken.set(x, 1);
      years++;
      
    }
    // simulate the process for some "years" but if you get stuck
    // with a node asleep and no more than 2 nodes to it, exit and print false
  }
  return 0;
}
