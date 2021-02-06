#include <iostream>
#include <vector>
#include <set>
#include <functional>
#include <tuple>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, k {};
  cin >> n >> k;
  vector<long long int> arr( n );
  for( int i = 0; i < n; ++ i )
    cin >> arr[i];
  vector<long long int> s( arr.begin(), arr.end() );
  for( int i = 1; i < n; ++ i )
    s[i] += s[i - 1];
  int len = 1, start = 0, finish = 0;
  long long total = s[0];
  set<tuple<int, int, int>> sols;
  tuple<int, int, int> tmp = {0, 0, 0};
  while( start <= finish and (start < n and finish < n) ){
    if( total >= k ){
      tmp = tie(len, start, finish);
      sols.emplace( tmp );
      total -= s[start];
      ++ start;
      -- len;
    }
    else{
      ++ finish;
      if( finish < n ){
	total = s[finish] - (start > 0 ? s[start-1] : 0);
	++ len;
      }
      else
	break;
    }
  }
  if( sols.size() ){
    auto ans = sols.begin();
    cout << (get<0>(*ans)) << '\n';
  }
  else
    cout << "-1\n";
  return 0;
}
