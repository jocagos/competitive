#include <stdio.h>

int main(){
  int i,t;
  scanf("%d", &t);
  for( i = 1; i <= t; ++i){
    int wb, we, mb, me, lh, lm, rh, rm;
    scanf("%d:%d %d:%d ", &lh, &lm, &rh, &rm);
    wb = lh * 60 + lm, we = rh * 60 + rm;
    scanf("%d:%d %d:%d ", &lh, &lm, &rh, &rm);
    mb = lh * 60 + lm, me = rh * 60 + rm;
    if( me < wb || mb > we ) printf("Case %d: Hits Meeting\n", i);
    else printf("Case %d: Mrs Meeting\n", i);
  }
  return 0;
}
