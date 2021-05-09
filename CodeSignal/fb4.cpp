#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> getList( vector<pair<int, int>>& vec ){
  unordered_map<int, int> reps;
  unordered_map<int, bool> used;
  unordered_map<int, unordered_set<int>> graph;
  for( auto& p : vec ){
    reps[p.first] ++;
    reps[p.second] ++;
    used[p.first] = false;
    used[p.second] = false;
    graph[p.first].emplace( p.second );
    graph[p.second].emplace( p.first );
  }
  int start {-1}, finnish {}, idx {};
  for( auto& p : reps )
    if( p.second == 1 ){
      if( start != -1 ){
	finnish = p.first;
	break;
      }
      else
	start = p.first;
    }
  vector<int> correctList( vec.size() + 1 );
  while( start != finnish ){
    used[start] = true;
    correctList[idx ++] = start;
    for( auto& x : graph[start] ){
      if( used[x] ) continue;
      start = x;
      break;
    }
  }
  correctList[idx] = finnish;
  return std::move( correctList );
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  cin >> n;
  vector<pair<int, int>> pairs( n - 1 );
  for( int i = 0; i < n - 1; ++ i )
    cin >> pairs[i].first >> pairs[i].second;
  vector<int> ans = getList( pairs );
  for( auto& x : ans )
    cout << x << " ";
  return 0;
}
