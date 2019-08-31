#include <stdio.h>
#include <math.h>

char word[10010], filler = 's', vowels[] = { 'a', 'e', 'i', 'o', 'u' };
int divs[10010];

int main(){
  int n;
  scanf("%d\n", &n);
  int i = 0, j = 0, r = 0, c = 0, didx = 2;
  divs[0] = 1; divs[1] = n;
  for( i = 2; i <= sqrt( n ); ++ i ){
    if( n % i == 0 ){
      divs[didx ++] = n / i;
      if( n / i != i ) divs[didx ++] = i;
      /* printf("found %d", n / i ); */
      if( n / i >= 5 && i >= 5 ){
	r = n / i;
	c = i;
	/* printf(" and %d", i ); */
      }
      /* printf("\n"); */
    }
  }
  /* printf("r: %d\tc: %d\n", r, c ); */
  if( r == 0 || c == 0 ) printf("-1\n");
  else{
    /* for( i = 0; i <= 2 * c; ++ i ) printf("_"); */
    /* printf("\n"); */
    for( i = 0; i < r; ++ i ){
      /* printf("|"); */
      for( j = 0; j < c; ++ j ){
	word[i + j * r] = vowels[(i + j)%5];
	/* printf("%c", word[i + j * r] ); */
      }
      /* printf("\n"); */
      /* for( j = 0; j <= 2 * c; ++ j ) printf("-"); */
      /* printf("\n"); */
    }
    printf("%s\n", word);
  }
  return 0;
}
