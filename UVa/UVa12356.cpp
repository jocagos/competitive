#include <iostream>
#include <set>
#include <cstdlib>
using namespace std;
// slow, uses set. should be improved by using an array of values (instead of set) and using binary search that returns -1 or the min value greater/max value lesser than X.
int main(){
  int s, b;
  while( scanf("%d %d ", &s, &b), s || b ){
    int arr[s];
    for( int i = 0; i < s; ++i ) arr[i] = i+1;
    set<int> elements(arr, arr+s);
    for( int i = 0; i < b; ++i ){
      int l, r;
      scanf("%d %d ", &l, &r);
      auto _l = elements.find(l), _r = elements.upper_bound(r);
      elements.erase(_l, _r);
      _l = elements.lower_bound(r);
      _r = elements.upper_bound(l);
      cout << (_l != elements.begin() ? to_string(*(--_l)) : "*") << " " << (_r != elements.end() ? to_string(*_r) : "*") << endl;
    }
    printf("-\n");
  }
  return 0;
}
