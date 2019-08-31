#include <bits/stdc++.h>

using namespace std;

class Cmp{
public:
  bool operator()( pair<int, int> left, pair<int, int> right ){
    return ( left.second != right.second ? left.second < right.second : left.first < right.first );
  }
};

unordered_map<int, int> jumps;
vector<vector<pair<int, int>>> AdjList( 100000, vector<pair<int, int>>() );
int n, m;

int sssp( int source, int target ){
  jumps[source] = -1;
  int cost = 0, prev = source;
  priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;
  for( auto x : AdjList[source] ){
    if( x.first == target ) return x.second + cost;
    else pq.push( x );
  }
  while( !pq.empty() ){
    pair<int, int> tmp = pq.top();
    source = tmp.first;
    jumps[source] = prev;
    prev = source;
    cost += tmp.second;
    pq.pop();
    for( auto x : AdjList[source] ){
      if( x.first == target ) return x.second + cost;
      else pq.push( x );
    }
  }
  return cost;
}

int main(){
  //  ios_base::sync_with_stdio(false);
  //  cin.tie(0);
  //  cout.tie(0);
  while( cin >> n ){
    cin >> m;
    cout << " " << n << '\t' << " " << m << endl;
    int from, to, weight;
    for( int i = 0; i < m; ++ i ){
      cin >> from >> to >> weight;
      cout << "got: " << from << " " << to << " " << weight << endl;
      AdjList[from].emplace_back( to, weight );
    }
    int cost = sssp( 0, n - 1 );
    stack<int> st;
    int it = n - 1;
    while( jumps[it] != -1 ) st.push( it ), it = jumps[it];
    cout << cost << " " << st.size() + 1 << '\n';
  }
  return 0;
}
