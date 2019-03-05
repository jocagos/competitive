#include <iostream>
#include <deque>
#include <cmath>

using namespace std;

int main(){
  int n, k, r, maxSize = 0;
  cin >> n >> k;
  deque<int> q;
  while( n -- ){
    cin >> r;
    q.push_back(r);
    while( !q.empty() and q.back() - q.front() >= 1000 ) q.pop_front();
    if( q.size() > maxSize ) maxSize = q.size();
  }
  int ans = ceil( 1.0 * maxSize / k );
  cout << ans << endl;
  return 0;
}
