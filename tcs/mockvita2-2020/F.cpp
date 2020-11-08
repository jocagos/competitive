#include <iostream>
#include <algorithm>

using namespace std;

constexpr long long MOD = 1000000007;

long long gcd( long long a, long long b ){
  if( b == 0 ) return a;
  else return gcd( b, a % b );
}

long long comb( int n, int r ){
  long long num = 1LL, den = 1LL, res;
  for( long long itr = 1LL; itr <= r; ++ itr ){
    den = den * itr;
    num = num * (n - (itr - 1LL));
  }
  res = num / den;
  return res;
}

long long mult_inv( long long a ){
  long long b {};
  for( long long itr = 1LL; itr < MOD; ++ itr ){
    if( (itr * MOD + 1) % a == 0 ){
      b = (itr * MOD + 1) / a;
      break;
    }
  }
  return b;
}

int main(){
  long long TC;
  scanf("%lld", &TC);
  while( TC -- ){
    long long pool, learnt, chosen, unknown, gcd_res, ans;
    long long ways_choose, ways_fail, p, q;
    scanf("%lld %lld %lld", &pool, &learnt, &chosen );
    unknown = pool - learnt;
    ways_choose = comb( pool, chosen );
    ways_fail = comb( unknown, chosen );
    p = ways_choose - ways_fail;
    q = ways_choose;
    gcd_res = gcd(p, q);
    if( gcd_res != 1LL ){
      p = p / gcd_res;
      q = q / gcd_res;
    }
    ans = (p * mult_inv( q ) % MOD );
    printf("%lld\n", ans);
  }
  return 0;
}
