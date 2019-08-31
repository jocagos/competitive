#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <sstream>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

constexpr int MAXN = 250;
constexpr long long LLINF = 4e18;

int p[MAXN][2]; // points
double al[MAXN][MAXN]; // adj mat
string line;

int main(){
  fastio;
  getline( cin, line ); // read tc
  int tc = stoi( line ); // get tc
  getline( cin, line ); // blank
  while( tc -- ){
    int pidx = 0; // point qty, sub qty
    bool first = true; // first line of input
    for( int i = 0; i < MAXN; ++ i ) for( int j = 0; j < MAXN; ++ j ) al[i][j] = 0; // reset
    while( getline( cin, line ), line != "" ){ // read until blank
      istringstream iss( line ); // get vals as cin
      if( first ){
	iss >> p[0][0] >> p[0][1] >> p[1][0] >> p[1][1]; // source - target
	pidx = 2; // points
	first = false; // stop reading this way
      }
      else{
	int a, b;
	iss >> a >> b; // read first point
	// save point
	p[pidx][0] = a;
	p[pidx][1] = b;
	pidx ++;
	while( iss >> a >> b ){
	  if( a == -1 or b == -1 ) break;
	  // assign point
	  p[pidx][0] = a;
	  p[pidx][1] = b;
	  // store dist
	  al[pidx - 1][pidx] = al[pidx][pidx - 1] = hypot( p[pidx][0] - p[pidx - 1][0], p[pidx][1] - p[pidx - 1][1] );
	  pidx ++; // up the points
	}
      }
    }
    for( int i = 0; i < pidx; ++ i ) al[i][i] = LLINF; // init
    for( int i = 0; i < pidx; ++ i ){
      for( int j = 0; j < pidx; ++ j ){
	if( i == j ) continue; // skip
	if( al[i][j] == 0 ){
	  al[j][i] = al[i][j] = 4 * hypot( p[i][0] - p[j][0], p[i][1] - p[j][1] ); // init
	}
      }
    }
    double dist[MAXN]; // for dijkstra
    dist[0] = 0;
    // source is 0, target is 1
    for( int i = 1; i < pidx; ++ i ) dist[i] = LLINF; // init
    // priority queue
    // fffffsssss this wasn't working ONLY BECAUSE I used the comparator with the node number too
    // forgot to put it in the lambda and it throws the correct answer now
    auto lambda = []( pair< double, int >& left, pair< double, int >& right ){ return left.first < right.first; };
    priority_queue< pair<double, int>, vector< pair< double, int > >, decltype( lambda ) > pq( lambda );
    pq.emplace( 0, 0 ); // push source
    while( not pq.empty() ){
      auto t = pq.top(); // pop top
      pq.pop(); // pop
      double d = t.first; // curr dist
      int i = t.second; // curr node
      if( d > dist[t.second] ) continue; // if current distance greater than recorded
      for( int j = 0; j < pidx; ++ j ){
    	if( j == i ) continue; // skip self loop
    	if( dist[i] + al[i][j] < dist[j] ){ // if lesser dist
    	  dist[j] = dist[i] + al[i][j]; // keep it
    	  pq.emplace( dist[j], j ); // emplace next node
    	}
      }
    }
    al[0][1] = dist[1];
    // floyd warshall, O(n3)
    // for( int k = 0; k < pidx; ++ k ) for( int i = 0; i < pidx; ++ i ) for( int j = 0; j < pidx; ++ j ) al[i][j] = min( al[i][j], al[i][k] + al[k][j] );
    int ans = int(al[0][1] * 6 / 4000 + 0.5); // auto ceil
    cout << ans << ( tc ? "\n\n" : "\n" );
  }
  return 0;
}
