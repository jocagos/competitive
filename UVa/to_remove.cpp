// Simple Dijkstra Seen from Destination to all vertex v in the set of V.
// Jair Said Hernández Reyes.
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<ii>
#define oo 100000000000
ll T, N, M, E, D, TLE, W, X, Y;
vii V[10000];
ll dist[10000];
priority_queue<ii, vector<ii>, greater<ii> >pq;
int main(){
  cin >> T;
  while(T--){
    cin >> N >> D >> TLE >> M;
    for(ll i = 1; i <= N + 3; i++){
      dist[i] = oo; 
      V[i].clear();
    }
    for(ll i = 0; i < M ; i ++){
      cin >> X >> Y >> W;
      V[Y].push_back(ii(X, W));
    }
    pq.push(ii(0, D));
    dist[D] = 0;
    while(!pq.empty()){
      ii head = pq.top();
      pq.pop();
      ll u = head.second;
      ll d = head.first;
      if(d > dist[u])
	continue;
      for(ll i = 0; i < V[u].size(); i++){
	ll v  = V[u][i].first;
	if(dist[u] + V[u][i].second  < dist[v]){
	  dist[v]  = dist[u] + V[u][i].second;
	  pq.push(ii(dist[v], v));
	}
      }
    }
    ll ans = 0;
    for(ll i = 1; i <= N; i++)
      if(dist[i] <= TLE)
	ans++;
    printf("%lld\n", ans);
    if (T) 
      puts("");	
  }
  return 0;
}
