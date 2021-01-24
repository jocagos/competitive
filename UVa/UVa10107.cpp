#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
constexpr int MAXN = 10001;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  priority_queue<int> LEFT;
  priority_queue<int, vector<int>, greater<int>> RIGHT;
  int val, idx {}, med {};
  cin >> val;
  med = val;
  cout << med << '\n';
  LEFT.push( val );
  while( cin >> val ){
    if( LEFT.size() > RIGHT.size() ){
      if( val < med ){
	RIGHT.push( LEFT.top() );
	LEFT.pop();
	LEFT.push( val );
      }
      else
	RIGHT.push( val );
      med = (LEFT.top() + RIGHT.top());
      med >>= 1; // divide by 2
    }
    else if( LEFT.size() == RIGHT.size() ){
      if( val < med ){
	LEFT.push( val );
	med = LEFT.top();
      }
      else{
	RIGHT.push( val );
	med = RIGHT.top();
      }
    }
    else{
      if( val > med ){
	LEFT.push( RIGHT.top() );
	RIGHT.pop();
	RIGHT.push( val );
      }
      else
	LEFT.push( val );
      med = (LEFT.top() + RIGHT.top());
      med >>= 1;
    }
    cout << med << '\n';
  }
  return 0;
}
