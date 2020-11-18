#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main(){
  int n {};
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  priority_queue<int, std::vector<int>, std::greater<int> > pq;
  while( cin >> n, n ){
    int tmp {};
    int total {};
    for( int i = 0; i < n; ++ i ){
      cin >> tmp;
      pq.emplace( tmp );
    }
    while( !pq.empty() or pq.size() == 1 ){
      // sacar dos, sumarlos, anadir el valor al costo
      // meter a la cola
      int a = pq.top();
      pq.pop();
      if( pq.size() >= 1 ){
	int b = pq.top();
	pq.pop();
	total += a + b;
	pq.emplace( a + b );
      }
    }
    cout << total << '\n';
  }
  return 0;
}
