#include <algorithm>
#include <iostream>

using namespace std;

int main(){
  int n, k;
  int arr[1000000];
  while( scanf("%d %d", &n, &k) != EOF ){
    memset(arr, 0, sizeof arr);
    for( int i = 0; i < n; ++i ) scanf("%d", &arr[i]);
    int l, r, k;
    for( int i = 0; i < q; ++i ){
      scanf("%d %d %d", &l, &r, &k);
      // Need to sort [l, r] with at most 100 "steps"
      // such that if q = 10 ** 6 then we can access k optimally
      // Idea: sort the queries from leftmost, least width query, to
      // rightmost, least width and to most width query such that we
      // can linearly scan the array and sort it part by part
      // thus "sub-sorting" and, at the very end, the most width queries
      // will need no further sorting or very little sorting.
      // Hard part: how to sort queries? queryCmp( A, B )
    }
  }
  return 0;
}
