#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int main(){
  int m, n;
  while( scanf("%d %d", &m, &n ) != EOF ){
    vvii adjList(m+1);
    for( int i = 1; i <= m; ++i ){
      int r, tmp;
      scanf("%d", &r);
      if( r == 0 ) continue;
      adjList[i].resize(r);
      for( int j = 0; j < r; ++j ){
	scanf("%d", &tmp);
	adjList[i][j].second = tmp;
      }
      for( int j = 0; j < r; ++j ){
	scanf("%d", &tmp);
	adjList[i][j].first = tmp;
      }
    }
    vvii transAdjList(n+1);
    for( int i = 1; i <= m; ++i ){
      for( int j = 0; j < adjList[i].size(); ++j ){
	transAdjList[ adjList[i][j].second ].emplace_back( adjList[i][j].first, i );
      }
    }
    cout << n << " " << m << endl;
    for( int i = 1; i <= n; ++i ){
      cout << transAdjList[i].size();
      if( transAdjList[i].size() == 0 ){
	cout << endl << endl;
	continue;
      }
      else{
	for( int j = 0; j < transAdjList[i].size(); ++j ){
	  cout << " " << transAdjList[i][j].second << (j + 1 == transAdjList[i].size() ? "\n" : "" );
	}
	for( int j = 0; j < transAdjList[i].size(); ++j ){
	  cout  << transAdjList[i][j].first << (j + 1 == transAdjList[i].size() ? "\n" : " " );
	}
      }
    }
  }
  return 0;
}
