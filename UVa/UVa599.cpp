#include <iostream>
#include <sstream>
#include <vector>
#include <bitset>

using namespace std;
typedef vector<int> vi;

/* The following class was imported from `Competitive Programming 3' */
/* If you need more info about how it works, check the book! */
class UnionFind {
private:
  vi p, rank, setSize;
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) { 
    if (!isSameSet(i, j)) { numSets--; 
    int x = findSet(i), y = findSet(j);
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int main(){
  int t;
  scanf("%d ", &t); // read that pesky whitespace
  while(t--){
    vector<string> lines; // We're gonna read the connections and store them since we need to check what nodes are actually going to be used.
    string line {}; // dummy string for every line
    while( true ){
      getline(cin, line);
      if( line == "" ) break; // if we ever hit eof let's exit
      if( line[0] == '*' ) break; // if we ever hit a '*' let's process the nodes
      lines.push_back(line); // otherwise, just push the line!
    }
    getline(cin, line); // Read nodes to use
    bitset<30> nodes; nodes.reset(); // to check whether a node is a tree/acorn or not
    // Set all bits to use to 1
    for( int i = 0; i < line.length(); ++i ){
      if( line[i] != '\r' and line[i] != ',' and line[i] != '\n' ) nodes.set((int)(line[i]-'A'), 1);
    }
    UnionFind trees(30); // Let's make the magic happen
    for( auto& x : lines ){
      // for every line let's read the connection and store it
      trees.unionSet( x[1]-'A', x[3]-'A' );
      // also let's set one used node as 'member' and not 'root'
      nodes.set(x[3]-'A', 0);
    }
    for( int i = 0; i < nodes.size(); ++i ){
      if( nodes[i] ){ // if it 'is' a tree we're gonna check that
	int parentI = trees.findSet(i); // store the parent
	for( int j = i+1; j < nodes.size(); ++j ){ // check all other nodes
	  // if parent is already present in another 'tree', let's mark
	  // it as a member and not as a root
	  if( nodes[j] and (parentI == trees.findSet(j)) ) nodes.set(j, 0);
	}
      }
    }
    int treeCount = 0, acornCount = 0;
    for( int i = 0; i < nodes.size(); ++i ){
      if( nodes[i] ){ // Count acorns and trees
	if( trees.sizeOfSet(i) > 1 ) treeCount++;
	else if( trees.sizeOfSet(i) == 1 ) acornCount++;
      }
    }
    // Just output the count
    cout << "There are " << treeCount << " tree(s) and " << acornCount << " acorn(s)." << endl;
  }
  return 0;
}
