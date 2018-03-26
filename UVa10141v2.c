#include <stdio.h>
#include <string.h>
#include <float.h>
#include <stdlib.h>

int main(){
  int n, p, ii = 1;
  while( scanf("%d %d", &n, &p), n || p ){
    double mincost = DBL_MAX, cost;
    int reqmet, maxreq = -1;
    char * buf = (char * )malloc(sizeof(char)*90);
    char * ans = (char * )malloc(sizeof(char)*90);
    size_t size = 90;
    int i, j;
    for( i = 0; i < n; ++i ){
      getline(&buf, &size, stdin);
    }
    while( p-- ){
      getline(&buf, &size, stdin);
      scanf("%lf %d", &cost, &reqmet);
      if( reqmet > maxreq ){
	maxreq = reqmet;
	mincost = cost;
	strcpy(ans, buf);
      }
      else if( reqmet == maxreq && cost < mincost ){
	maxreq = reqmet;
	mincost = cost;
	strcpy(ans, buf);
      }
      for( j = 0; j < reqmet; ++j ) getline(&buf, &size, stdin);
    }
    if( ii > 1 ) printf("\n");
    printf("RFP #%d\n%s\n", ii++, ans);
  }
  return 0;
}
