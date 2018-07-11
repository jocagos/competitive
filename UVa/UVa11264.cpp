#include <iostream>
#include <vector>

using namespace std;

int main(){
  int t;
  cin >> t;
  while( t -- ) {
    int n;
    vector<long long> coins;
    long long sum = 0;
    cin >> n;
    while( n -- ){
      long long v;
      cin >> v;
      coins.push_back(v);
    }
    int count = (coins.size() > 1 ? 2 : 1 );
    sum = 1;
    for( int i = 1; i < coins.size() - 1; ++ i ){
      if( sum + coins[i] < coins[i+1] ) sum += coins[i], count++;
    }
    cout << count << endl;
  }
  return 0;
}
