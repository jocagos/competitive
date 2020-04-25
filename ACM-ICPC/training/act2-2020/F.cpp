#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;
constexpr int MAXN = 100100;
int n {}, c {};
bitset<MAXN> used( 0 );

int main(){
  cin >> n >> c;
  vector<int> w( n );
  for( int i = 0; i < n; ++ i ){
    cin >> w[i];
  }
  sort( w.begin(), w.begin() + n );
  int amount {};
  for( int i = 0; i < n; ++ i ){
    if( used[i] )
      continue;
    used[i] = 1;
    int pos = lower_bound( w.rbegin(), w.rend(), c - w[i], greater<int>() ) - w.rbegin();
    for( pos; pos < n and used[n - pos - 1]; ++ pos );
    if( pos != n )
      if( w[i] + w[n - pos - 1] <= c )
	used[n - pos - 1] = 1;
    amount ++;
  }
  cout << amount << endl;
  return 0;
}
