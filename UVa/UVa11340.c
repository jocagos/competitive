#include <string.h>
#include <stdio.h>
/* This solutions runs ~40% of the time of the C++ map solution which I include anyways */
int main(){
  int t;
  int vals[260];
  scanf("%d ", &t);
  while(t--){
    memset(vals, 0, sizeof vals);
    int k, v, sum = 0, nl = 0;
    char c;
    scanf("%d ", &k);
    while(k--){
      scanf("%c %d ", &c, &v);
      vals[c+128] = v;
    }
    scanf("%d ", &k);
    while( nl < k ){
      c = getchar();
      if( c == '\n' ) nl++;
      sum += vals[c+128];
    }
    printf("%d.%02d$\n", sum / 100, sum % 100);
  }
  return 0;
}
