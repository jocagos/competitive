#include <iostream>
#include <vector>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all( c ) (c).begin(), (c).end()
#define justN( c, n ) (c).begin(), (c).begin() + n
#define FOR( i, start, end ) for( int i(start); i != end; ++ i )
#define REP( i, end ) FOR( i, 0, end )

using namespace std;

int main(){
  int t;
  fastio;
  cin >> t;
  vector<long long> coins(1000, 0);
  while( t -- ) {
    int n;
    long long sum = 0;
    cin >> n;
    REP(i, n) cin >> coins[i];
    int count = ( n > 1 ? 2 : 1 );
    sum = 1;
    for( int i = 1; i < n - 1; ++ i ){
      if( sum + coins[i] < coins[i+1] ) sum += coins[i], count++;
    }
    cout << count << '\n';
  }
  return 0;
}
