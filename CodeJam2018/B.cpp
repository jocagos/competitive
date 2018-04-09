#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

void tsort( int * arr, int n ){
  bool done = false;
  while(!done){
    done = true;
    for( int i = 0; i < n-2; ++i ){
      if( arr[i] > arr[i+2] ){
	done = false;
	int tmp = arr[i];
	arr[i] = arr[i+2];
	arr[i+2] = tmp;
      }
    }
  }
}

int main(){
  int t;
  scanf("%d ", &t);
  vector<int> vi(100000);
  int vi2[100000];
  for( int i = 1; i <= t; ++i ){
    printf("Case #%d: ", i);
    int n, tmp;
    scanf("%d ", &n);
    for( int j = 0; j < n; ++j ){
      scanf("%d", &tmp);
      vi[j] = vi2[j] = tmp;
    }
    sort(vi.begin(), vi.begin() + n);
    tsort(vi2, n);
    bool ok = true;
    int idx;
    for( int j = 0; j < n; ++j )
      if( vi[j] != vi2[j] ){
	ok = false;
	idx = j;
	break;
      }
    if( ok ) printf("OK\n");
    else printf("%d\n", idx);
  }
  return 0;
}
