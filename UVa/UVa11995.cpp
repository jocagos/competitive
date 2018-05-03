#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(){
  int n;
  while( scanf("%d", &n) != EOF ){
    if( n == 0 ) continue;
    stack<int> s;
    queue<int> q;
    priority_queue<int> pq;
    bool is_s {true}, is_q {true}, is_pq {true};
    for( int i = 0, a, b; i < n; ++i ){
      scanf("%d %d", &a, &b);
      if( a == 1 ){
	if( is_s ) s.push(b);
	if( is_q ) q.push(b);
	if( is_pq ) pq.push(b);
      }
      else if( a == 2 ){
	if( is_s ){
	  if( s.empty() or s.top() != b ) is_s = false;
	  else s.pop();
	}
	if( is_q ){
	  if( q.empty() or q.front() != b ) is_q = false;
	  else q.pop();
	}
	if( is_pq ){
	  if( pq.empty() or pq.top() != b ) is_pq = false;
	  else pq.pop();
	}
      }
    }
    if( is_s and !is_q and !is_pq ) cout << "stack" << endl;
    else if( is_q and !is_s and !is_pq ) cout << "queue" << endl;
    else if( is_pq and !is_q and !is_s ) cout << "priority queue" << endl;
    else if( !is_s and !is_q and !is_pq ) cout << "impossible" << endl;
    else cout << "not sure" << endl;
  }
  return 0;
}
