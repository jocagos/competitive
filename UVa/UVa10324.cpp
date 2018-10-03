#include <iostream>
#define MAX 1000005
#define oio() ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main(){
  char s[MAX];
  int sum[MAX];
  int n, i, j, c = 1;
  //  oio();
  while( scanf("%s %d", s, &n) == 2 ){
    sum[0] = 0;
    for( i = 1; i < MAX; ++i ){
      sum[i] = sum[i-1] + s[i-1] - '0';
    }
    printf("Case %d:\n", c++);
    while(n--){
      scanf("%d %d", &i, &j);
      if( i > j ){
	int tmp = j;
	j = i;
	i = tmp;
      }
      i++;j++;
      if( i == j ) printf("Yes\n");
      else if( sum[j] - sum[i-1] == 0 || sum[j] - sum[i-1] == j-i+1 ) printf("Yes\n");
      else printf("No\n");
    }
  }
}
