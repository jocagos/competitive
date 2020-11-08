#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  vector<int> fact(11, 1);
  for( int i = 1; i < 11; ++ i )
    fact[i] = fact[i - 1] * i;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N {};
  cin >> N;
  int K {};
  while( N ){
    auto it = lower_bound( begin( fact ), end( fact ), N );
    if( it != end( fact ) ){
      while( it >= begin( fact ) and *it > N ) it --;
      N -= *it;
      ++ K;
    }
  }
  cout << K << '\n';
  return 0;
}
