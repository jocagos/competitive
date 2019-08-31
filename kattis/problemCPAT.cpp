#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <ctime>
#include <chrono>
#include <functional>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>

using namespace std;

typedef pair<int, int> point;
typedef pair<point, int> tern;
template <class T> using minFibonacciHeap = __gnu_pbds::priority_queue<T, greater<T>, __gnu_pbds::thin_heap_tag>;
template <class T> using minBinHeap = __gnu_pbds::priority_queue<T, greater<T>, __gnu_pbds::rc_binomial_heap_tag>;

bool fibo = false;
bool bino = false;

inline int getPos( point p, int width ){ return p.first + p.second * width; }

inline point getPoint( int pos, int width ){
  point p;
  p.first = pos % width;
  p.second = pos / width;
  return p;
}

inline int manhattan( int x1, int y1, int x2, int y2 ){
  return abs(x1 - x2) + abs(y1 - y2);
}

inline vector<point> getNeighbors( point p, const int width, const int height, const unsigned char* pMap ){
  vector<point> neighbors;
  if( p.first > 0 and pMap[p.first-1 + p.second*width] == 1 ) neighbors.emplace_back( p.first - 1, p.second );
  if( p.first + 1 < width and pMap[p.first+1 + p.second*width] == 1 ) neighbors.emplace_back( p.first + 1, p.second );
  if( p.second > 0 and pMap[p.first + (p.second-1)*width] == 1) neighbors.emplace_back( p.first, p.second - 1 );
  if( p.second + 1 < height and pMap[p.first + (p.second+1)*width] == 1) neighbors.emplace_back( p.first, p.second + 1 );
  return neighbors;
}

int FindPath(const int nStartX, const int nStartY, const int nTargetX, const int nTargetY, const unsigned char* pMap, const int nMapWidth, const int nMapHeight, int* pOutBuffer, const int nOutBufferSize){
  // A* search, we make a min-heap priority queue
  //priority_queue<tern, vector<tern>, greater<tern>> frontier;
  //minFibonacciHeap<tern> frontier; fibo = true;
  minBinHeap<tern> frontier; bino = true;
  // and two hash tables to store the costs and the path
  unordered_map<int, int> path;
  unordered_map<int, int> cost;
  // we store the initial node with 0 as priority though priority
  // doesn't matter that much since it will always pop this node first
  point p(nStartX, nStartY), goal(nTargetX, nTargetY);
  tern tmpT( p, 0 );
  frontier.push( tmpT );
  // now we store in two pairs the start and end for easy access
  // and create a vector to store the neighbors to visit from every node
  vector<point> neighbors;
  // initialize the hash tables
  path[getPos(p, nMapWidth)] = getPos(p, nMapWidth);
  cost[getPos(p, nMapWidth)] = 0;
  // and while there's a neighbor to pop we loop
  while( !frontier.empty() ){
    tern t = frontier.top();
    point current(t.first);
    frontier.pop();
    // if we get to the goal just exit
    if( current == goal ) break;
    // compute neighbors
    neighbors = getNeighbors( current, nMapWidth, nMapHeight, pMap );
    // for every neighbor
    for( point next : neighbors ){
      // get a new cost based on previous cost and cost of a movement (1)
      int newCost = cost[getPos(current, nMapWidth)] + 1;
      // if that node has no cost yet, or it has a higher cost, update
      if( cost.find(getPos(next, nMapWidth)) == cost.end() or newCost < cost[getPos(next, nMapWidth)] ){
        // update hash table
        cost[getPos(next, nMapWidth)] = newCost;
        // create priority based on heuristic
        int priority = newCost + manhattan( next.first, next.second, goal.first, goal.second );
        // and push it to the min-heap
        tmpT = {next, priority};
        frontier.push( tmpT );
        // then update hash table
        path[getPos(next, nMapWidth)] = getPos(current, nMapWidth);
      }
    }
  }
  //reconstruct path
  // in case we did not reach goal
  if( path.find( getPos(goal, nMapWidth) ) == path.end() ) return -1;
  deque<int> reconstruct;
  // first get the first node visited
  int next = getPos(goal, nMapWidth), last = getPos(p, nMapWidth);
  while( next != last ){
    reconstruct.push_front( next );
    next = path[next];
  }
  // If the size of the solution is higher
  int total = reconstruct.size();
  if( total > nOutBufferSize ){
    // realloc pOutBuffer with more size
    pOutBuffer = new int[total+1];
    // I think it would be better to not call again FindPath but actually use the results already computed so you don't have to do it again.
    if( pOutBuffer ){
      while( !reconstruct.empty() ){
	*(pOutBuffer++) = reconstruct.front();
	reconstruct.pop_front();
      }
      return total;
    }
    else return -1;
    
  }
  else{
    while( !reconstruct.empty() ){
      *(pOutBuffer++) = reconstruct.front();
      reconstruct.pop_front();
    }
    return total;
  }
}

using namespace std::chrono;

int main(){
  unsigned char * pMap;
  int * pOutBuffer;
  int nMapWidth, nMapHeight, nStartX, nStartY, nGoalX, nGoalY, bufSize, tmp;
  high_resolution_clock::time_point start = high_resolution_clock::now();
  // clock_t start = time(nullptr);
  scanf("%d %d", &nMapHeight, &nMapWidth);
  pMap = (unsigned char*) malloc( nMapHeight * nMapWidth );
  for( int i = 0; i < nMapHeight; ++ i ){
    for( int j = 0; j < nMapWidth; ++ j ){
      scanf("%d", &tmp);
      pMap[j + i*nMapWidth] = tmp;
    }
  }
  scanf("%d %d", &nStartX, &nStartY );
  scanf("%d %d", &nGoalX, &nGoalY );
  scanf("%d", &bufSize );
  pOutBuffer = (int*) malloc( bufSize * sizeof(int) );
  // clock_t end = time(nullptr);
  high_resolution_clock::time_point end = high_resolution_clock::now();
  auto readingTime = duration_cast<microseconds>( end - start ).count();
  start = high_resolution_clock::now();
  int len = FindPath(nStartX, nStartY, nGoalX, nGoalY, pMap, nMapWidth, nMapHeight, pOutBuffer, bufSize );
  end = high_resolution_clock::now();
  cout << "Dimensions: " << nMapWidth << " x " << nMapHeight << endl;
  cout << "Start: (" << nStartX << ", " << nStartY << ")\tGoal: (" << nGoalX << ", " << nGoalY << ")\n";
  cout << "Direct Manhattan is " << manhattan(nStartX, nStartY, nGoalX, nGoalY) << endl;
  cout << "len is " << len << endl;
  auto algorithmTime = duration_cast<microseconds>( end - start ).count();
  cout << "time spent reading data (printf/scanf): " << readingTime << " = " << (1.0L*readingTime / 1000000) << "s" << endl;
  cout << "time spent in `FindPath` with " << (fibo ? "FibonacciHeap" : ((bino) ? "BinomialHeap" : "PairingHeap")) << ": " << algorithmTime << " = " << (1.0L*algorithmTime / 1000000) << "s" << endl;
  //int len = FindPath(0, 0, 1, 2, pMap, 4, 3, pOutBuffer, 12);
  //if( len > 0 ) for( int i = 0; i < len; ++ i ) cout << pOutBuffer[i] << endl;
  if(pOutBuffer) free(pOutBuffer);
  if(pMap) free(pMap);
  cout << "----------------------" << endl;
  return 0;
}
