#include <iostream>
#include <deque>
#include <set>
constexpr int MAXN = 220;
using namespace std;
long long a[MAXN] {};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, k {};
  cin >> n >> k;
  for( int i = 0; i < n; ++ i ) cin >> a[i];
  deque<long long> q;
  set<long long> used;
  for( int i = 0; i < n; ++ i ){
    if( used.find( a[i] ) == used.end() ){
      // if it's not inside, do something!
      if( used.size() >= k ){
	long long b = q.back();
	q.pop_back();
	used.erase( used.lower_bound( b ) );
      }
      used.emplace( a[i] );
      q.push_front( a[i] );
    }
  }
  cout << used.size() << endl;
  while( not q.empty() ){
    cout << q.front() << (q.size() == 1U ? "\n" : " ");
    q.pop_front();
  }
  return 0;
}
