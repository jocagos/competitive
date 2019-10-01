#include <bits/stdc++.h>
constexpr int MAXN = 100100, INF = -1;
using namespace std;

// dp knapsack variant
// at each step pick n and delete n-1 and n+1 from a
// get the max number of points by maximizing steps taken
// since each step taken yields n points
// bottom up fashion

int n {};
long long dp[MAXN] {};
map<long long, long long> bucket {};
vector<pair<long long, long long>> pairs {};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for( int i = 1; i < MAXN; ++ i ) dp[i] = INF;
  for( int i = 0; i < n; ++ i ){
    int tmp {};
    cin >> tmp;
    bucket[tmp] ++;
  }
  pairs.assign( bucket.begin(), bucket.end() );
  for( int i = 0; i < pairs.size(); ++ i ){
    int pos = i - 1;
    while( pos >= 0 and pairs[pos].first + 1 == pairs[i].first ) pos --;
    if( pos == -1 ) dp[i] = 1LL * pairs[i].first * pairs[i].second;
    else dp[i] = dp[pos] + 1LL * pairs[i].first * pairs[i].second;
    if( i ) dp[i] = max( dp[i], dp[i - 1] );
  }
  cout << dp[pairs.size() - 1] << endl;
  return 0;
}
