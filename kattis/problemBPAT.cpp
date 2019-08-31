#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n, k, r;
  cin >> n >> k;
  vector<int> reqs(101, 0);
  for( int i = 0; i < n; ++ i ){
    cin >> r;
    reqs[r/1000]++;
  }
  // check the max number of requests made per period (1000 miliseconds per period) and store it at 'max'
  // then just answer 'max/k + 1' if k does not divide max
  int m = *max_element(reqs.begin(), reqs.end());
  cout << (m + k - 1) / k << endl;
  return 0;
}
