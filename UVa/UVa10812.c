#include <stdio.h>

int main(){
  int t;
  long long a, b;
  scanf("%d", &t);
  while( t-- ){
    scanf("%lld %lld", &a, &b);
    /* probably needs big nums so I did it with python but general case is as follows: */
    /*
     * Suppose you are given two numbers a, b such that:
       * x + y = a (1)
       * |x - y| = b -> sqrt((x-y)^2) = b (2)
     * Thus, you can easily (with algebraic manipulations) obtain:
       * (a + b) * (a - b) / 4 = x*y (3)
     * Nothe that:
       * x = a - y -> |a - 2*y| = b -> 2 cases:
         * a > 2*y -> a - b = 2*y -> (a - b) / 2 = y
	 * a < 2*y -> a + b = 2*y -> (a + b) / 2 = y
     * Therefore, given any a, b > 0 such that (1), (2) holds, either:
       * x = (a + b)/2
       * x = (a - b)/2
     * Then we can observe y is the other because of (3).
     * So if we just get (a + b) and check if it's odd, we know it's impossible
     * for a solution to exist because that number can't be divided properly
     * by two (given that 'divided properly' means yielding an integer).
    */
    long long either = (a+b)/2;
    long long other = (a-b)/2;
    if( other > either ){
      long long tmp = either;
      either = other;
      other = tmp;
    }
    if( either < 0 || other < 0 || (a-b) % 2 ) printf("impossible\n");
    else printf("%lld %lld\n", either, other);
  }
  return 0;
}
