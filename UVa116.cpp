#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> mii;

int main(){
  mii weights;
  weights.resize(10);
  for( int i = 0; i < 10; ++i ) weights[i].resize(100);
  int n, m, i, j, t;
  while( scanf("%d %d", &n, &m) != EOF ){
    // I/O
    for( i = 0; i < n; ++i ){
      for( j = 0; j < m; ++j ){
	scanf("%d", &t);
	weights[i][j] = {t, 11};
      }
    }
    // code here
    for( j = 1; j < m; ++j ){
      for( i = 0; i < n; ++i ){ // DP in place
	int tmp = weights[i][j].first;
      	int _m = min( min( weights[(i-1 < 0 ? n-1 : i-1)][j-1].first, weights[i][j-1].first ), weights[(i+1)%n][j-1].first );
	weights[i][j].first += _m;
	if( _m == weights[(i-1 < 0 ? n-1 : i -1)][j-1].first && weights[(i-1 < 0 ? n-1 : i-1)][j-1].second < i ) weights[(i-1 < 0 ? n-1 : i-1 )][j-1].second = i;
	if( _m == weights[i][j-1].first && weights[i][j-1].second < i ) weights[i][j-1].second = i;
	if( _m == weights[(i+1)%n][j-1].first && weights[(i+1)%n][j-1].second < i ) weights[(i+1)%n][j-1].second = i;
	// Add memo to remember the origin node
	/*
	if( weights[i][j].second == -1 ){	  
	  int w = weights[i][j].first;
	  if( weights[i][j-1].first == w-tmp ) weights[i][j].second = i;
	  else if( weights[(i+1)%n][j-1].first == w-tmp ) weights[i][j].second = (i+1) % n;
	  else weights[i][j].second = (i-1 < 0 ? n-1 : i-1 );
	}
	*/
      }
      
    }
    int minWeight = 0;
    for( i = 1; i < n; ++i )
      if( weights[i][m-1].first < weights[minWeight][m-1].first )
	minWeight = i;
    int mimi = minWeight;
    int nmin = 0;
    for( i = 0; i < n; ++i ) if( weights[i][m-1].first == weights[mimi][m-1].first ) nmin++;
    set<string> vs;
    for( i = 0; i < n && nmin; ++i ){
      if( weights[mimi][m-1].first == weights[i][m-1].first ){
	minWeight = i;
        string minPath = to_string(minWeight+1);
	//    string minPath = to_string((minWeight+1)%n);
	for( i = m-1; i > 0; --i ){
	  minPath = to_string( weights[minWeight][i].second+1 ) + " " + minPath;
	  //      minPath = to_string((weights[minWeight][i].second+1)%n) + " " + minPath;
	  minWeight = weights[minWeight][i].second;
	}
	nmin--;
	vs.insert(minPath);
      }
      else continue;
    }
    string s = *(vs.begin());
    mimi = stoi(s.substr(s.length()-1))-1;
    cout << *(vs.begin()) << endl;
    cout << weights[mimi][m-1].first << endl;
  }

  return 0;
}
