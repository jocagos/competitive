#include <stdio.h>

int main(){
  int t, i;
  scanf("%d ", &t);
  for( i = 1; i <= t; ++i ){
    int ad, am, ay, bd, bm, by;
    scanf("%d/%d/%d\n%d/%d/%d ", &ad, &am, &ay, &bd, &bm, &by);
    if( by > ay ) printf("Case #%d: Invalid birth date\n", i);
    else if( by == ay && bm > am ) printf("Case #%d: Invalid birth date\n", i);
    else if( by == ay && bm == am && bd > ad ) printf("Case #%d: Invalid birth date\n", i);
    else if( ay - by > 131 ) printf("Case #%d: Check birth date\n", i);
    else if( ay - by == 131 && ( bm < am || (bm == am && bd <= ad))) printf("Case #%d: Check birth date\n", i);
    else if( ay == by && am == bm && ad == bd ) printf("Case #%d: 0\n", i);
    else printf("Case #%d: %d\n", i, ay-by - (bm > am ? 1 : (bm == am && bd > ad ? 1 : 0 ) ) );
  }
  return 0;
}
