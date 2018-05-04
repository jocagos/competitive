#include <iostream>
#include <vector>

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
  scanf("%d", &t);
  while(t--){
    int n, a, b;
    char c;
    scanf("%d ", &n);
    UnionFind computers(n+1);
    int success = 0, unsuccess = 0;
    while( scanf("%c %d %d ", &c, &a, &b) == 3 ){
      if( c == 'c' ) computers.unionSet(a, b);
      if( c == 'q' ) ( computers.isSameSet( a, b ) ? success++ : unsuccess++ );
    }
    cout << success << "," << unsuccess << endl;
    if( t ) cout << endl;
  }
  return 0;
}
