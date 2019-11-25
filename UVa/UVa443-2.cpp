#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

inline string suffix( int n ){
  int res10 = n % 10, res100 = n % 100;
  if( res100 == 11 or res100 == 12 or res100 == 13 ) return "th";
  else if( res10 == 1 ) return "st";
  else if( res10 == 2 ) return "nd";
  else if( res10 == 3 ) return "rd";
  else return "th";
}

int main() {
  map<i64, bool> done;
  i64 a[5843];
  priority_queue<i64, vector<i64>, greater<i64>> pq;
  pq.emplace( 1 );
  for( int i = 1; i <= 5842; ++ i ){
    i64 n = pq.top();
    a[i] = n;
    pq.pop();
    for( auto d : { 2, 3, 5, 7 } ){
      i64 next = n * d;
      if( not done[next] ){
	done[next] = true;
	pq.emplace( next );
      }
    }
  }
  int n;
  while( cin >> n, n )
    cout << "The " << n << suffix(n) << " humble number is " << a[n] << ".\n";
  return 0;
}
