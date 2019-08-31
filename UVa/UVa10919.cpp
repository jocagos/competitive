#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int kk, mm;
  while(scanf("%d %d", &kk, &mm) == 2){
    int k = kk, m = mm;
    vector<int> freddie;
    int t;
    while( k-- ){ scanf("%d", &t); freddie.push_back(t);}
    bool passed = true;
    while(m--){
      int c, p;
      scanf("%d %d", &c, &p);
      while(c--){
	int ct;
	scanf("%d", &ct);
	if( find(freddie.begin(), freddie.end(), ct) != freddie.end()) p--;
      }
      if( p <= 0 ) continue;
      else{
	printf("no\n");
	passed = false;
	break;
      }
    }
    if( m > 0 && !passed ){
      while( m-- ){
	int c, p, ct; scanf("%d %d", &c, &p);
	while(c--) scanf("%d", &ct);
      }
    }
    else{
      printf("yes\n");
    }
  }
  return 0;
}
