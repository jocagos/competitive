#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define VISITED 1
#define UNVISITED -1

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int cycles( vector<vi>& adjList ){
  bool visited[adjList.size()];
  for( int i = 0; i < adjList.size(); ++i ) visited[i] = false;
  visited[1] = true;
  for( int i = 0; i < adjList[
}

int main(){
  int vertices, edges;
  scanf("%d %d", &vertices, &edges);
  vector<vi> adjList(vertices+1);
  for( int i = 0, a, b; i < edges; ++i ){
    scanf("%d %d", a, b);
    adjList[a].emplace_back(b);
    adjList[b].emplace_back(a);
  }
  
  return 0;
}
