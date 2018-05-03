#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int n;
  while( scanf("%d", &n), n ){
    priority_queue<int, vector<int>, greater<int>> add;
    long cost = 0;
    for( int i = 0, t; i < n; ++i ){
      scanf("%d", &t);
      add.push(t);
    }
    while( add.size() >= 2 ){
      int p = add.top(), q;
      add.pop();
      q = add.top();
      add.pop();
      cost += p+q;
      add.emplace(p+q);
    }
    printf("%ld\n", cost);
  }
  return 0;
}
